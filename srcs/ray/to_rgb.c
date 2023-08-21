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

static t_rgb	_apply_amb_light(
	const t_scene *scene,
	const t_ray *ray,
	const t_hit *hit
)
{
	t_vec3	tmp;
	double	ref_rate;

	tmp = vec3_reflect(
			vec3_mul(ray->direction, -1),
			hit->normal
			);
	ref_rate = scene->amb_light.ratio;
	ref_rate *= vec3_dot(hit->normal, vec3_normalize(tmp));
	return (brend_rgb(
			scene->amb_light.color,
			hit->obj->sphere.color,
			ref_rate)
	);
}

__attribute__((nonnull))
t_rgb	ray_to_rgb(
	t_ray ray,
	const t_scene *scene
)
{
	t_hit	hit;
	t_rgb	color;
	t_objs	*objs;

	objs = (t_objs *)(scene->objs.p);
	hit = (t_hit){0};
	if (!ray_hit_any(&ray, objs, scene->objs.len, &hit))
		return ((t_rgb){0});
	color = _apply_amb_light(scene, &ray, &hit);
	return (color);
}
