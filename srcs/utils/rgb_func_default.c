/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_func_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:10:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/07 23:12:18 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

__attribute__((nonnull))
t_rgb	rgb_color_default(
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
