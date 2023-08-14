/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:09:51 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/11 21:39:11 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "rt_types.h"
# include "ray.h"

t_objs	sphere_init(
			t_vec3 center,
			double diameter,
			t_rgb color
			)
		;

bool	sphere_hit(
			const t_objs *obj,
			const t_ray *ray,
			const double t_range[2],
			t_hit *hit_rec
			)
		__attribute__((nonnull))
		;

t_rgb	sphere_color(
			const t_objs *obj,
			const t_ray *ray,
			double hit_at
			)
		__attribute__((nonnull))
		;

#endif
