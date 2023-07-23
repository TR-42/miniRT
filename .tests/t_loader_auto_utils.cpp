/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_loader_auto_utils.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:18:54 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/23 00:38:55 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#ifndef DOUBLE_ALLOWABLE_ERROR
#define DOUBLE_ALLOWABLE_ERROR 1e-10
#endif

extern "C"
{
	#include <rt_types.h>
	#include "_get_lderr_str.h"
	#include "_print_rgb.h"
	#include "_print_vec3.h"
	#include "t_obj_print/_print_obj.h"
}

#define FORMAT_RED "\e[0;31m"
#define FORMAT_GREEN "\e[0;32m"
#define FORMAT_RESET "\e[0m"

t_rgb	_rgb(
	t_byte r,
	t_byte g,
	t_byte b
)
{
	t_rgb	v;

	v.r = r;
	v.g = g;
	v.b = b;
	return (v);
}

t_vec3	_vec3(
	double x,
	double y,
	double z
)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

template<typename T>
class Dump
{
public:
	void _(T& _v)
	{
		this->_(_v, sizeof(T));
	}

	void _(T& v, size_t len)
	{
		unsigned char *p = (unsigned char *)(void *)&v;

		for (size_t i = 0; i < len; ++i)
			printf("%02x%c", p[i], i == (len - 1) ? '\n' : '-');
	}

	void _(T& v, size_t len, T& orig)
	{
		unsigned char *p = (unsigned char *)(void *)&v;
		unsigned char *p_orig = (unsigned char *)(void *)&orig;

		for (size_t i = 0; i < len; ++i)
		{
			char sep = i == (len - 1) ? '\n' : '-';
			const char *fmt = "%02x%c";
			if (p[i] != p_orig[i])
				fmt = FORMAT_RED "%02x" FORMAT_RESET "%c";
			printf(fmt, p[i], sep);
		}
	}
};

class Tester
{
private:
	t_scene	scene;
	t_lderr	lderr;
	bool	is_success;
	const char	*input;

	void _print(t_amb_light v)
	{
		printf("\tRatio: %f\n", v.ratio);
		_print_rgb("Color", v.color);
	}

	void _print(t_cam v)
	{
		_print_vec3("View Point", v.point);
		_print_vec3("Orientation", v.orientation);
		printf("\tFOV: %d\n", v.fov);
	}

	void _print(t_light v)
	{
		_print_vec3("Light Point", v.point);
		printf("\tBrightness: %f\n", v.brightness);
		_print_rgb("Color", v.color);
	}

	void _print(t_objs v)
	{
		_print_obj(v);
	}

	void _print(t_spher v)
	{
		_print_sphere(v);
	}

	void _print(t_plane v)
	{
		_print_plane(v);
	}

	void _print(t_cylnd v)
	{
		_print_cylinder(v);
	}

	#define CMP_IMPL(type) bool _cmp(const type& a, const type& b) const { return (a == b); }
	CMP_IMPL(t_byte)
	CMP_IMPL(int)
	#undef CMP_IMPL

	bool _cmp(const double& a, const double& b) const
	{
		if (a == b)
			return (true);
		double diff = a - b;
		if (diff < 0)
			diff *= -1;
		return (diff < DOUBLE_ALLOWABLE_ERROR);
	}

	#define CMP_IMPL_1(v) (_cmp(a.v, b.v))
	#define CMP_IMPL_2(v, ...) CMP_IMPL_1(__VA_ARGS__) && CMP_IMPL_1(v)
	#define CMP_IMPL_3(v, ...) CMP_IMPL_2(__VA_ARGS__) && CMP_IMPL_1(v)
	#define CMP_IMPL_4(v, ...) CMP_IMPL_3(__VA_ARGS__) && CMP_IMPL_1(v)
	#define CMP_IMPL_5(v, ...) CMP_IMPL_4(__VA_ARGS__) && CMP_IMPL_1(v)
	#define CMP_IMPL_6(v, ...) CMP_IMPL_5(__VA_ARGS__) && CMP_IMPL_1(v)
	#define CMP_IMPL(i, type, ...)\
	bool _cmp(const type& a, const type& b) const\
	{ return (CMP_IMPL_##i(__VA_ARGS__)); }

	CMP_IMPL(3, t_rgb, r, g, b)
	CMP_IMPL(3, t_vec3, x, y, z)

	CMP_IMPL(2, t_amb_light, ratio, color)
	CMP_IMPL(3, t_cam, point, orientation, fov)
	CMP_IMPL(3, t_light, point, brightness, color)

	CMP_IMPL(1, t_objs_comm, type)
	CMP_IMPL(4, t_spher, comm, center, diameter, color)
	CMP_IMPL(4, t_plane, comm, center, orientation, color)
	CMP_IMPL(6, t_cylnd, comm, center, axis, diameter, height, color)

	#define CMP_OBJ(type, obj_name) case type: return _cmp(a.obj_name, b.obj_name);
	bool _cmp(const t_objs& a, const t_objs& b) const
	{
		if (a.comm.type != b.comm.type)
			return (false);
		switch (a.comm.type)
		{
			CMP_OBJ(T_OBJ_CYLINDER, cylinder)
			CMP_OBJ(T_OBJ_PLANE, plane)
			CMP_OBJ(T_OBJ_SPHERE, sphere)
			default:
				return (false);
		}
	}

	#undef CMP_IMPL_1
	#undef CMP_IMPL_2
	#undef CMP_IMPL_3
	#undef CMP_IMPL_4

public:
	Tester(
		const char *input
	);
	~Tester();

	void	t(
		t_lderr expected
	);

	void	t(
		t_amb_light expected
	);

	void	t(
		t_cam expected
	);

	void	t(
		t_light expected
	);

	void	t(
		t_objs expected
	);
	void	t(
		t_spher expected
	);

	void	t(
		t_plane expected
	);

	void	t(
		t_cylnd expected
	);
};

Tester::Tester(
	const char *input
)
{
	bzero(&(this->scene), sizeof(t_scene));
	this->scene.objs = vect_init(4, sizeof(t_objs));
	if (this->scene.objs.p == NULL)
	{
		perror("test/initTester/vect_init");
		exit(1);
	}
	this->input = input;
	this->lderr = load_rt_line(input, &(this->scene));
	this->is_success = (this->lderr == LOAD_ERR_SUCCESS);
}

Tester::~Tester()
{
	vect_dispose(&(this->scene.objs));
}

#define MSG_OK FORMAT_GREEN "[OK]" FORMAT_RESET
#define MSG_KO FORMAT_RED "[KO]" FORMAT_RESET

#define ERR_NOT_SAME(expected)\
	printf(MSG_KO " expected `%s` but was `%s`\n",\
		_get_lderr_str(expected),\
		_get_lderr_str(this->lderr))

#define ERR_CHK if (!this->is_success) { ERR_NOT_SAME(LOAD_ERR_SUCCESS); return; }

#define FLAG_CHK(flag) if (!scene.flag) { puts(MSG_KO " " #flag " flag was down!"); }

#define SAME_CHK(target, type, size)\
	if (_cmp(expected, target))\
		puts(MSG_OK);\
	else {\
		Dump<type> p;\
		printf(MSG_KO "(input: `%s`)\n", input);\
		puts("Expected:"); p._(expected, size); this->_print(expected);\
		puts("But was:"); p._(target, size, expected); this->_print(target);\
	}

#define OBJ_LEN_CHK if (scene.objs.len != 1) { puts(MSG_KO " objs array was not 1"); return; }

void	Tester::t(
	t_lderr expected
)
{
	if (this->lderr == expected)
		puts(MSG_OK);
	else
		ERR_NOT_SAME(expected);
}

#define TEST_IMPL(type, flag, target, size)\
void Tester::t(type expected)\
{ ERR_CHK; FLAG_CHK(flag) SAME_CHK(target, type, size) }

TEST_IMPL(t_amb_light, is_amb_l_set, scene.amb_light,
	sizeof(double) + sizeof(t_rgb))
TEST_IMPL(t_cam, is_camera_set, scene.camera,
	sizeof(t_vec3) + sizeof(t_vec3) + sizeof(t_byte))
TEST_IMPL(t_light, is_light_set, scene.light,
	sizeof(t_vec3) + sizeof(double) + sizeof(t_rgb))

void Tester::t(
	t_objs expected
)
{
	ERR_CHK;
	OBJ_LEN_CHK
	SAME_CHK(*(t_objs *)(scene.objs.p), t_objs, sizeof(t_objs))
}

#define OBJ_TEST_INPL(c_type, obj_type)\
void Tester::t(c_type expected)\
{ t_objs v; bzero(&v, sizeof(t_objs)); v.obj_type = expected; this->t(v); }

OBJ_TEST_INPL(t_spher, sphere)
OBJ_TEST_INPL(t_plane, plane)
OBJ_TEST_INPL(t_cylnd, cylinder)
