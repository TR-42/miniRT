/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_load_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:09:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:48:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <rt_loader.h>
#include <utils.h>

#include "_get_lderr_str.h"
#include "_print_rgb.h"
#include "_print_vec3.h"
#include "t_obj_print/_print_obj.h"

static void	_print_objs(const t_scene *s)
{
	t_objs	*arr;
	size_t	i;

	printf("Objects Count: %zu\n", s->objs.len);
	arr = (t_objs *)(s->objs.p);
	i = 0;
	while (i < s->objs.len)
	{
		printf("[%zu]: ", i);
		_print_obj(arr[i++]);
	}
}

static void	_print_scene(const t_scene *s)
{
	printf("Ambient Lightning: %d\n", s->is_amb_l_set);
	printf("\tRatio: %f\n", s->amb_light.ratio);
	_print_rgb("Color", s->amb_light.color);
	printf("Camera: %d\n", s->is_camera_set);
	_print_vec3("View Point", s->camera.point);
	_print_vec3("Orientation", s->camera.orientation);
	printf("\tFOV: %lf\n", s->camera.fov);
	printf("Light: %d\n", s->is_light_set);
	_print_vec3("Light Point", s->light.point);
	printf("\tBrightness: %f\n", s->light.brightness);
	_print_rgb("Color", s->light.color);
	_print_objs(s);
}

int	main(int argc, const char *argv[])
{
	t_scene	scene;
	t_lderr	err;
	int		fd;

	fd = STDIN_FILENO;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			perr_exit(argv[1]);
	}
	err = load_rt(fd, &scene);
	printf("err: %s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", _get_lderr_str(err));
	_print_scene(&scene);
	if (scene.objs.p != NULL)
		vect_dispose(&(scene.objs));
	if (fd != STDIN_FILENO)
		close(fd);
	fflush(stdout);
}

#define DEBUG_LEAKS_CMD_LEN (32)

__attribute__((destructor))
static void	destructor(void) {
	char	cmd[DEBUG_LEAKS_CMD_LEN];

	if (getenv("DEBUG") == NULL)
		return ;
	snprintf(cmd, DEBUG_LEAKS_CMD_LEN, "leaks %d", getpid());
	system(cmd);
}
