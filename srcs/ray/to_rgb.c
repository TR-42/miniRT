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

#include <math.h>

#include <scene.h>

#define CALL_CNT_MAX 50

static t_rgb	_brend_rgb(
	t_rgb a,
	t_rgb b
)
{
	return ((t_rgb){
		.r = ((int)a.r * b.r) / 255,
		.g = ((int)a.g * b.g) / 255,
		.b = ((int)a.b * b.b) / 255,
	});
}

static t_rgb	_get_sky_color(t_ray ray)
{
	double	t;

	t = fabs(ray.direction.y + 1) / 2;
	return ((t_rgb){
		.r = (0.5 + (0.5 * t)) * 255.9999,
		.g = (0.7 + (0.3 * t)) * 255.9999,
		.b = (1.0 + (0.0 * t)) * 255.9999,
	});
}

__attribute__((nonnull))
t_rgb	ray_to_rgb(
	t_ray ray,
	const t_objs *objs,
	size_t objs_len,
	size_t call_cnt
)
{
	t_hit	hit;
	t_rgb	color;

	color = _get_sky_color(ray);
	if (CALL_CNT_MAX < ++call_cnt)
		return (color);
	hit = (t_hit){0};
	if (!ray_hit_any(&ray, objs, objs_len, &hit))
		return (color);
	ray.origin = hit.at;
	ray.direction = vec3_normalize(vec3_sub(ray.direction,
				vec3_mul(hit.normal, 2 * vec3_dot(ray.direction, hit.normal))));
	color = ray_to_rgb(ray, objs, objs_len, call_cnt);
	return (_brend_rgb(color, hit.obj->sphere.color));
}
