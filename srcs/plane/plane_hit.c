/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:40:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/04 21:55:20 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <plane.h>
#include <utils.h>

// ref: https://knzw.tech/raytracing/?page_id=78
// レイと平面の交差判定
__attribute__((nonnull))
bool	plane_hit(
	const t_objs *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	double	t;
	double	denom;

	if (obj->comm.type != T_OBJ_PLANE)
		return (false);
	denom = vec3_dot(ray->direction, obj->plane.orientation);
	if (denom == 0)
		return (false);
	t = (vec3_dot(obj->plane.point, obj->plane.orientation) \
		- vec3_dot(ray->origin, obj->plane.orientation)) / denom;
	if (t_range[0] < t && t < t_range[1]
		&& 90 <= vec3_deg(ray->direction, obj->plane.orientation))
	{
		hit_rec->t = t;
		hit_rec->at = ray_at(ray, t);
		hit_rec->normal = obj->plane.orientation;
		return (true);
	}
	return (false);
}
