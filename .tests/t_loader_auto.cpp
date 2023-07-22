/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_loader_auto.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:14:42 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/23 00:39:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>

extern "C"
{
	#include <rt_loader.h>
}

#define DOUBLE_ALLOWABLE_ERROR 1e-12
#include "t_loader_auto_utils.cpp"

#define T(i, input, expected) { std::printf("%lu: ", i); Tester(input).t(expected); }

int	main(void)
{
	size_t	i = 0;

	T(++i,
		"A 0.2 255,255,255",
		((t_amb_light){
			.ratio = 0.2,
			.color = _rgb(255,255,255),
		})
	)

	T(++i,
		"C -50.0,0,20 0,0,1 70",
		((t_cam){
			.point = _vec3(-50, 0, 20),
			.orientation = _vec3(0, 0, 1),
			.fov = 70,
		})
	)

	T(++i,
		"L -40.0,50.0,0.0 0.5 10,0,255",
		((t_light){
			.point = _vec3(-40, 50, 0),
			.brightness = 0.5,
			.color = _rgb(10, 0, 255),
		})
	)

	T(++i,
		"sp 0.0,0.0,20.6 12.6 10,0,255",
		((t_spher){
			.comm.type = T_OBJ_SPHERE,
			.center = _vec3(0, 0, 20.6),
			.diameter = 12.6,
			.color = _rgb(10, 0, 255),
		})
	)

	T(++i,
		"pl 0.0,0.0,-32.0 0.0,1.0,0.0 0,0,225",
		((t_plane){
			.comm.type = T_OBJ_PLANE,
			.center = _vec3(0, 0, -32),
			.orientation = _vec3(0, 1, 0),
			.color = _rgb(0, 0, 225),
		})
	)

	T(++i,
		"cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255",
		((t_cylnd){
			.comm.type = T_OBJ_CYLINDER,
			.center = _vec3(50, 0, 20.6),
			.axis = _vec3(0, 0, 1),
			.diameter = 14.2,
			.height = 21.42,
			.color = _rgb(10, 0, 255),
		})
	)
	return (0);
}
