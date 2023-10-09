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
