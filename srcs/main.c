/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:50:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/10 00:21:57 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <camera.h>
#include <canvas.h>
#include <rt_loader.h>
#include <print_inline_img.h>
#include <utils.h>

#include <scene.h>

#define CANVAS_HEIGHT 480
#define CANVAS_WIDTH 640

#if defined(DEBUG) || defined(ENABLE_PNG)

size_t	g_debug_x;
size_t	g_debug_y;

static void	_set_debug_x_y(
	size_t x,
	size_t y
)
{
	g_debug_x = x;
	g_debug_y = y;
}

#else

static void	_set_debug_x_y(
	size_t x,
	size_t y
)
{
	(void)x;
	(void)y;
}

#endif

static void	_set_gradient(
	t_cnvas *canvas,
	const t_scene *scene
)
{
	int		ix;
	int		iy;
	t_ray	ray;

	iy = 0;
	while (iy < CANVAS_HEIGHT)
	{
		ix = 0;
		while (ix < CANVAS_WIDTH)
		{
			_set_debug_x_y(ix, iy);
			ray = cam_get_ray(&(scene->camera), canvas, ix, iy);
			canvas_set_color(canvas, ix, iy, ray_to_rgb(ray, scene));
			ix += 1;
		}
		iy += 1;
	}
}

__attribute__((nonnull))
static bool	_load_rt_file(
	const char *fname,
	t_scene *dst
)
{
	int		fd;
	t_lderr	err;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (perr_retint("open RT file", false));
	err = load_rt(fd, dst);
	if (err == LOAD_ERR_SUCCESS)
		return (true);
	vect_dispose(&(dst->objs));
	print_load_err(err);
	return (false);
}

int	main(
	int argc,
	const char *argv[]
)
{
	t_cnvas	canvas;
	t_scene	scene;
	t_byte	*tmp;
	size_t	len;
	int		ret;

	if (argc != 2)
		return (errstr_retint("usage", "miniRT <RT file name>", EXIT_FAILURE));
	if (!canvas_init(&canvas, CANVAS_HEIGHT, CANVAS_WIDTH))
		return (perr_retint("canvas_init", 1));
	if (!_load_rt_file(argv[1], &scene))
	{
		canvas_dispose(&canvas);
		return (EXIT_FAILURE);
	}
	_set_gradient(&canvas, &scene);
	tmp = NULL;
	len = canvas_to_png(&canvas, &tmp);
	canvas_dispose(&canvas);
	vect_dispose(&(scene.objs));
	ret = print_inline_img(tmp, len);
	if (!ret)
		perr_retint("print_inline_img", 0);
	free(tmp);
	return (!ret);
}
