/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:50:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/13 19:42:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sphere.h>

__attribute__((nonnull))
t_rgb	sphere_color(
	const t_objs *obj,
	const t_ray *ray,
	double hit_at
)
{
	t_vec3	n;

	(void)obj;
	n = vec3_normalize(vec3_sub(ray_at(ray, hit_at), vec3_(0, 0, -1)));
	return ((t_rgb){
		.r = (n.x + 1) * 127.99,
		.g = (n.y + 1) * 127.99,
		.b = (n.z + 1) * 127.99,
	});
}
