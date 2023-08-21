/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:30:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/17 22:44:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <utils.h>

__attribute__((nonnull))
t_rgb	ray_to_rgb(
	t_ray ray,
	const t_scene *scene
)
{
	t_hit	hit;
	t_rgb	color;
	t_objs	*objs;
	double	ref_rate;

	objs = (t_objs *)(scene->objs.p);
	hit = (t_hit){0};
	if (!ray_hit_any(&ray, objs, scene->objs.len, &hit))
		return ((t_rgb){0});
	color = scene->amb_light.color;
	ref_rate = scene->amb_light.ratio;
	ray.origin = hit.at;
	ray.direction = vec3_normalize(vec3_sub(ray.direction,
				vec3_mul(hit.normal, 2 * vec3_dot(ray.direction, hit.normal))));
	ref_rate = vec3_dot(hit.normal, ray.direction) * ref_rate;
	return (brend_rgb(color, hit.obj->sphere.color, ref_rate));
}
