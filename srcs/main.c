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

#include <math.h>

#include <camera.h>
#include <canvas.h>
#include <print_inline_img.h>
#include <utils.h>

#define CANVAS_HEIGHT 480
#define CANVAS_WIDTH 640

static t_rgb	_ray_to_rgb(t_ray ray)
{
	return ((t_rgb){
		.r = abs((int)(ray.direction.x * 255)),
		.g = abs((int)(ray.direction.y * 255)),
		.b = abs((int)(ray.direction.z * 255)),
	});
}

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
		.point = vec3_(0, 0, 0),
		.orientation = vec3_normalize(vec3_(1, 1, 1)),
		.fov = 60,
	};
	while (iy < CANVAS_HEIGHT)
	{
		ix = 0;
		while (ix < CANVAS_WIDTH)
		{
			ray = cam_get_ray(&cam, canvas, ix, iy);
			canvas_set_color(canvas, ix, iy, _ray_to_rgb(ray));
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
