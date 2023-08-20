/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:50:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/08 19:51:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include <math.h>

#include <camera.h>
#include <canvas.h>
#include <print_inline_img.h>
#include <utils.h>

#include <sphere.h>
#include <scene.h>

#define CANVAS_HEIGHT 480
#define CANVAS_WIDTH 640
#define RAY_CHK_MAX 16

static t_objs	g_obj_arr[16];

static void	_set_gradient(
	t_cnvas *canvas
)
{
	int		ix;
	int		iy;
	t_cam	cam;
	t_ray	ray;

	iy = 0;
	cam = (t_cam){
		.point = vec3_(0, 2, 5),
		.orientation = vec3_normalize(vec3_(0, 3, 10)),
		.fov = 50,
	};
	while (iy < CANVAS_HEIGHT)
	{
		ix = 0;
		while (ix < CANVAS_WIDTH)
		{
			ray = cam_get_ray(&cam, canvas, ix, iy);
			canvas_set_color(canvas, ix, iy, ray_to_rgb(ray, g_obj_arr, 6));
			ix += 1;
		}
		iy += 1;
	}
}

int	main(
	int argc,
	const char *argv[]
)
{
	t_cnvas	canvas;
	t_byte	*tmp;
	size_t	len;
	int		ret;

	(void)argc;
	(void)argv;
	if (!canvas_init(&canvas, CANVAS_HEIGHT, CANVAS_WIDTH))
		return (perr_retint("canvas_init", 1));
	g_obj_arr[0] = sphere_init(vec3_(0, 0, -2), 0.6, (t_rgb){255, 0, 0});
	g_obj_arr[1] = sphere_init(vec3_(0, -100, 0), 99, (t_rgb){0, 255, 0});
	g_obj_arr[2] = sphere_init(vec3_(1, -0.7, -2), 0.4, (t_rgb){255, 0, 255});
	g_obj_arr[3] = sphere_init(vec3_(2, 0, -3), 0.4, (t_rgb){255, 255, 0});
	g_obj_arr[4] = sphere_init(vec3_(-1, -0.2, -2), 0.4, (t_rgb){0, 0, 255});
	g_obj_arr[5] = sphere_init(vec3_(-2, -0.6, -3), 0.4, (t_rgb){0, 255, 255});
	_set_gradient(&canvas);
	tmp = NULL;
	len = canvas_to_png(&canvas, &tmp);
	canvas_dispose(&canvas);
	ret = print_inline_img(tmp, len);
	if (!ret)
		perr_retint("print_inline_img", 0);
	free(tmp);
	return (!ret);
}
