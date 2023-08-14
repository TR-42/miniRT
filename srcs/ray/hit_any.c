/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_any.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:30:54 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/14 01:05:32 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

__attribute__((nonnull))
bool	ray_hit_any(
	const t_ray *ray,
	const t_objs *objs,
	size_t objs_len,
	t_hit *hit_rec
)
{
	size_t	i;
	double	closest_so_far;
	bool	hit_anything;
	t_hit	_hit_rec;

	i = 0;
	closest_so_far = __DBL_MAX__;
	hit_anything = false;
	while (i < objs_len)
	{
		if (objs[i].comm.hit_func(objs + i, ray,
				(double [2]){0.0001, closest_so_far}, &_hit_rec))
		{
			hit_anything = true;
			closest_so_far = _hit_rec.t;
			*hit_rec = _hit_rec;
			hit_rec->obj = objs + i;
		}
		i += 1;
	}
	return (hit_anything);
}
