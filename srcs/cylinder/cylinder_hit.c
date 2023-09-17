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

#include <cylinder.h>

// ref: https://knzw.tech/raytracing/?page_id=19
// #toc-03476ddd7e79e9c8fa7d759966a93ba4-13

static bool	_cylinder_hit(
	const t_cylnd *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	(void)obj;
	(void)ray;
	(void)t_range;
	(void)hit_rec;
	return (false);
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
