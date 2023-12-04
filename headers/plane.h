/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:42:42 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/04 00:59:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "rt_types.h"
# include "ray.h"

t_objs	plane_init(
			t_vec3 point,
			t_vec3 orientation,
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

void	plane_init_f(t_plane *v);

#endif
