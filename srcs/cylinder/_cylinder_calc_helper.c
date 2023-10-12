/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cylinder_calc_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:13:25 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/10 00:22:41 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_cylinder_calc_helper.h"

#include <utils.h>

// center_tmp: rayの始点を一時的に原点と考えるため、オフセットをかけたもの
t_cyl_hlp	cyl_hlp_new(
	const t_cylnd *obj,
	const t_ray *ray
)
{
	t_cyl_hlp	v;
	t_vec3		center_tmp;

	v.l = ray->origin;
	v.v = ray->direction;
	center_tmp = vec3_sub(obj->center, v.l);
	v.p = vec3_sub(center_tmp, vec3_mul(obj->axis, obj->height / 2));
	v.p2 = vec3_add(center_tmp, vec3_mul(obj->axis, obj->height / 2));
	v.s = vec3_mul(obj->axis, obj->height);
	v.d_pp = vec3_dot(v.p, v.p);
	v.d_ps = vec3_dot(v.p, v.s);
	v.d_pv = vec3_dot(v.p, v.v);
	v.d_ss = vec3_dot(v.s, v.s);
	v.d_sv = vec3_dot(v.s, v.v);
	v.d_vv = vec3_dot(v.v, v.v);
	v.tmp_a = v.d_vv - (pow2f(v.d_sv) / v.d_ss);
	v.tmp_b = v.d_pv - (v.d_ps * v.d_sv / v.d_ss);
	v.tmp_c = v.d_pp - (pow2f(v.d_ps) / v.d_ss) - pow2f(obj->diameter / 2);
	v.is_hit_val = pow2f(v.tmp_b) - (v.tmp_a * v.tmp_c);
	return (v);
}

static void	_cyl_hlp2_set_min(
	t_cyl_hlp2 *v,
	t_vec3 n,
	t_vec3 p,
	double t
)
{
	v->n_ = n;
	v->p_ = p;
	v->t_ = t;
}

t_cyl_hlp2	cyl_hlp_top_btm_new(
	const t_cylnd *cylnd,
	const t_ray *ray
)
{
	t_cyl_hlp2	v;

	v.d_n_m = vec3_dot(cylnd->axis, ray->direction);
	if (v.d_n_m == 0)
		return (v);
	v.radius = cylnd->diameter / 2;
	v.h_half = cylnd->height / 2;
	v.n1 = vec3_mul(cylnd->axis, +1);
	v.p1 = vec3_add(cylnd->center, vec3_mul(v.n1, v.h_half));
	v.t1 = (vec3_dot(v.n1, v.p1) - vec3_dot(v.n1, ray->origin))
		/ vec3_dot(v.n1, ray->direction);
	v.n2 = vec3_mul(cylnd->axis, -1);
	v.p2 = vec3_add(cylnd->center, vec3_mul(v.n2, v.h_half));
	v.t2 = (vec3_dot(v.n2, v.p2) - vec3_dot(v.n2, ray->origin))
		/ vec3_dot(v.n2, ray->direction);
	if (v.t1 < v.t2)
		_cyl_hlp2_set_min(&v, v.n1, v.p1, v.t1);
	else
		_cyl_hlp2_set_min(&v, v.n2, v.p2, v.t2);
	v.hit_at = vec3_add(ray->origin, vec3_mul(ray->direction, v.t_));
	v.hit_r = vec3_len(vec3_sub(v.p_, v.hit_at));
	return (v);
}
