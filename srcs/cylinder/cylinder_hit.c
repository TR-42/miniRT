/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:05:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/18 02:09:02 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cylinder.h>

#include <vect3d.h>
#include <utils.h>

#include "_cylinder_calc_helper.h"

// ref: https://knzw.tech/raytracing/?page_id=19
// #toc-03476ddd7e79e9c8fa7d759966a93ba4-13
// ref: http://marupeke296.com/COL_3D_No25_RayToSilinder.html

// TODO: 底面に対してもhitを計算する
static bool	_get_hit_side(
	const t_cylnd *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	double		tmp;
	t_cyl_hlp	hlp;

	hlp = cyl_hlp_new(obj, ray);
	if (hlp.is_hit_val < 0)
		return (false);
	tmp = (hlp.tmp_b - sqrt(hlp.is_hit_val)) / hlp.tmp_a;
	if (tmp <= t_range[0] || t_range[1] <= tmp)
		return (false);
	hit_rec->at = vec3_add(hlp.l, vec3_mul(hlp.v, tmp));
	hit_rec->t = tmp;
	tmp = ((hit_rec->t * hlp.d_sv) - hlp.d_ps) / hlp.d_ss;
	hit_rec->normal = vec3_normalize(vec3_sub(
				hit_rec->at,
				vec3_add3(
					hlp.l,
					hlp.p,
					vec3_mul(hlp.s, tmp)
					)
				)
			);
	return (true);
}

static bool	_cylinder_hit(
	const t_cylnd *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	return (_get_hit_side(obj, ray, t_range, hit_rec));
}

__attribute__((nonnull))
bool	cylinder_hit(
	const t_objs *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	if (obj->comm.type != T_OBJ_CYLINDER)
		return (false);
	return (_cylinder_hit(&(obj->cylinder), ray, t_range, hit_rec));
}
