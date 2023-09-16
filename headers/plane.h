/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:42:42 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/17 00:42:43 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "rt_types.h"
# include "ray.h"

t_objs	plane_init(
			t_vec3 center,
			double diameter,
			t_rgb color
			)
		;

bool	plane_hit(
			const t_objs *obj,
			const t_ray *ray,
			const double t_range[2],
			t_hit *hit_rec
			)
		__attribute__((nonnull))
		;

t_rgb	plane_color(
			const t_objs *obj,
			const t_ray *ray,
			double hit_at
			)
		__attribute__((nonnull))
		;

void	plane_init_f(t_spher *v);

#endif
