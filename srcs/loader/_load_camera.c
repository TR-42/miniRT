/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 00:37:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 4

__attribute__((nonnull))
void	_load_camera(
	char *const arr[],
	t_scene *scene
)
{
	t_cam	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	v = (t_cam){0};
	v.point = _parse_vec3(arr[1], false);
	v.orientation = _parse_vec3(arr[2], true);
	if (!try_str_to_byte(arr[3], &(v.fov)) || 180 < v.fov)
		_err_val_out_of_range_exit();
	scene->is_camera_set = true;
	scene->camera = v;
}
