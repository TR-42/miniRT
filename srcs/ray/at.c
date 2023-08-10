/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:07:13 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/10 20:08:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

__attribute__((nonnull))
t_vec3	ray_at(
	const t_ray *ray,
	double t
)
{
	return (
		vec3_add(
			ray->origin,
			vec3_mul(ray->direction, t)
		)
	);
}
