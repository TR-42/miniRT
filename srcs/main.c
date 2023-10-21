/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:50:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:31:24 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// (for debug)
// - sprintf
#include <stdio.h>

#include <canvas.h>
#include <renderer.h>
#include <rt_loader.h>
#include <print_inline_img.h>
#include <utils.h>
#include <mymlx.h>

#define CANVAS_HEIGHT 480
#define CANVAS_WIDTH 640

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

#ifdef ENABLE_PNG

__attribute__((nonnull))
static bool	_do_show(
	t_cnvas *canvas,
	const t_scene *scene
)
{
	t_byte	*tmp;
	size_t	len;
	bool	ret;

	tmp = NULL;
	len = canvas_to_png(&canvas, &tmp);
	ret = print_inline_img(tmp, len);
	if (!ret)
		perr_retint("print_inline_img", false);
	free(tmp);
	return (ret);
}

#else

__attribute__((nonnull))
static bool	_do_show(
	t_cnvas *canvas,
	const t_scene *scene
)
{
	t_mymlx	mymlx;

	if (!mymlx_init(&mymlx, scene, canvas->width, canvas->height))
		return (perr_retint("mymlx_init", false));
	mymlx_set_image(&mymlx, canvas);
	mlx_loop(mymlx.mlx);
	mymlx_dispose(&mymlx);
	return (true);
}

#endif

int	main(
	int argc,
	const char *argv[]
)
{
	t_cnvas	canvas;
	t_scene	scene;
	bool	ret;

	if (argc != 2)
		return (errstr_retint("usage", "miniRT <RT file name>", EXIT_FAILURE));
	if (!canvas_init(&canvas, CANVAS_HEIGHT, CANVAS_WIDTH))
		return (perr_retint("canvas_init", 1));
	if (!_load_rt_file(argv[1], &scene))
	{
		canvas_dispose(&canvas);
		return (EXIT_FAILURE);
	}
	render(&canvas, &scene);
	ret = _do_show(&canvas, &scene);
	canvas_dispose(&canvas);
	vect_dispose(&(scene.objs));
	return (!ret);
}

#if DEBUG

# define DEBUG_LEAKS_CMD_LEN (32)

__attribute__((destructor))
static void	destructor(void) {
	char	cmd[DEBUG_LEAKS_CMD_LEN];

	if (getenv("DEBUG") == NULL)
		return ;
	snprintf(cmd, DEBUG_LEAKS_CMD_LEN, "leaks %d > /dev/stderr", getpid());
	system(cmd);
}

#endif
