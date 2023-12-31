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

#include <ft_mem/ft_mem.h>

#include <scene.h>
#include <utils.h>

// RRR: Reflection Rate Ratio
#define RRR_AMB 10
#define RRR_DIRECT 69
#define RRR_MIRROR 30
#define MIRROR_REF_ALPHA 8

static double	_get_amb_light_ref_rate(
	const t_scene *scene
)
{
	double	ref_rate;

	ref_rate = scene->amb_light.ratio;
	ref_rate *= (double)RRR_AMB / (RRR_AMB + RRR_DIRECT + RRR_MIRROR);
	return (ref_rate);
}

static double	_get_direct_ref_rate(
	const t_scene *scene,
	const t_hit *hit,
	const t_vec3 *hit_to_light
)
{
	double	dot_n_l;
	double	ref_rate;
	t_ray	ray_to_light;
	t_hit	tmp;
	double	hit_to_l_len;

	dot_n_l = vec3_dot(hit->normal, *hit_to_light);
	if (dot_n_l <= 0)
		return (0);
	ray_to_light.direction = *hit_to_light;
	ray_to_light.origin
		= vec3_add(hit->at, vec3_mul(*hit_to_light, 1. / 0xFFFF));
	hit_to_l_len = vec3_len(vec3_sub(scene->light.point, ray_to_light.origin));
	if (ray_hit_any(&ray_to_light, (t_objs *)scene->objs.p,
			scene->objs.len, &tmp) && tmp.t < hit_to_l_len)
		return (0);
	ray_to_light.origin = scene->light.point;
	ray_to_light.direction = vec3_mul(*hit_to_light, -1);
	if (ray_hit_any(&ray_to_light, (t_objs *)scene->objs.p,
			scene->objs.len, &tmp) && tmp.t < hit_to_l_len)
		return (0);
	ref_rate = scene->light.brightness;
	ref_rate *= (double)RRR_DIRECT / (RRR_AMB + RRR_DIRECT + RRR_MIRROR);
	ref_rate *= dot_n_l;
	return (ref_rate);
}

static double	_get_mirror_ref_rate(
	const t_scene *scene,
	const t_ray *ray,
	const t_hit *hit,
	const t_vec3 *hit_to_light
)
{
	double	ref_rate;
	double	dot_v_r;

	dot_v_r = vec3_dot(
			vec3_mul(ray->direction, -1),
			vec3_normalize(vec3_reflect(*hit_to_light, hit->normal))
			);
	if (dot_v_r <= 0)
		return (0);
	ref_rate = scene->light.brightness;
	ref_rate *= (double)RRR_MIRROR / (RRR_AMB + RRR_DIRECT + RRR_MIRROR);
	ref_rate *= pow(dot_v_r, MIRROR_REF_ALPHA);
	return (ref_rate);
}

__attribute__((nonnull))
t_rgb	ray_to_rgb(
	t_ray ray,
	const t_scene *scene
)
{
	t_hit	hit;
	t_objs	*objs;
	t_vec3	hit_to_light;
	double	ref_rate;

	objs = (t_objs *)(scene->objs.p);
	ft_bzero(&hit, sizeof(t_hit));
	if (!ray_hit_any(&ray, objs, scene->objs.len, &hit))
		return ((t_rgb){0});
	hit_to_light = vec3_normalize(vec3_sub(scene->light.point, hit.at));
	ref_rate = _get_direct_ref_rate(scene, &hit, &hit_to_light);
	if (ref_rate != 0)
		ref_rate += _get_mirror_ref_rate(scene, &ray, &hit, &hit_to_light);
	ref_rate += _get_amb_light_ref_rate(scene);
	return (brend_rgb(scene->amb_light.color,
			hit.obj->comm.rgb_func(hit.obj, &ray, hit.t),
			ref_rate));
}
