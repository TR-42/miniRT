/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:54 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/10 20:04:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vect3d.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

t_ray	ray_init_dst(
			t_vec3 origin,
			t_vec3 dst
			)
		;

t_vec3	ray_at(
			const t_ray *ray,
			double t
			)
		__attribute__((nonnull))
		;

#endif
