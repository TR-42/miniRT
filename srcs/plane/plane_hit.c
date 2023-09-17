/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:40:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/17 00:41:43 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <plane.h>
#include <utils.h>

// ref: https://knzw.tech/raytracing/?page_id=78
// レイと平面の交差判定
static bool	_plane_hit(
	const t_plane *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
}

__attribute__((nonnull))
bool	plane_hit(
	const t_objs *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	if (obj->comm.type != T_OBJ_PLANE)
		return (false);
	return (_plane_hit(&(obj->plane), ray, t_range, hit_rec));
}
