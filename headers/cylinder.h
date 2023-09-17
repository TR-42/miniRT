/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:06:12 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/18 02:14:57 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "rt_types.h"
# include "ray.h"

t_objs	cylinder_init(
			t_vec3 center_axis[2],
			double diameter_height[2],
			t_rgb color
			)
		;

bool	cylinder_hit(
			const t_objs *obj,
			const t_ray *ray,
			const double t_range[2],
			t_hit *hit_rec
			)
		__attribute__((nonnull))
		;

t_rgb	cylinder_color(
			const t_objs *obj,
			const t_ray *ray,
			double hit_at
			)
		__attribute__((nonnull))
		;

void	cylinder_init_f(t_cylnd *v);

#endif
