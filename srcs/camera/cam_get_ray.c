/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_get_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:48:03 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/11 00:52:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <camera.h>

// ref: https://www.scratchapixel.com/lessons/3d-basic-rendering/
//		ray-tracing-generating-camera-rays/generating-camera-rays.html
__attribute__((nonnull))
t_ray	cam_get_ray(
	const t_cam *cam,
	const t_cnvas *canvas,
	int x,
	int y
)
{
	t_ray	ray;
	double	fov_y;
	double	p[2];
	t_vec3	u;
	t_vec3	v;

	ray = (t_ray){0};
	if (canvas->width <= x
		|| canvas->height <= y)
		return (ray);
	ray.origin = cam->point;
	fov_y = (cam->fov / canvas->width) * canvas->height;
	p[0] = (2 * (((double)x + 0.5) / canvas->width) - 1)
		* tan((cam->fov / 2) * M_PI / 180);
	p[1] = (1 - (2 * ((double)y + 0.5) / canvas->height))
		* tan((fov_y / 2) * M_PI / 180);
	u = vec3_normalize(vec3_cross(vec3_(0, 1, 0),
				cam->orientation));
	v = vec3_cross(cam->orientation, u);
	ray.direction = vec3_normalize(vec3_add3(vec3_mul(u, p[0]),
				vec3_mul(v, p[1]), cam->orientation));
	return (ray);
}
