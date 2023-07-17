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
t_lderr	_load_camera(
	char *const arr[],
	t_scene *scene
)
{
	t_lderr	err;
	t_cam	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		return (LOAD_ERR_TOO_FEW_ARGS);
	v = (t_cam){0};
	err = _parse_vec3(arr[1], false, &(v.point));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	err = _parse_vec3(arr[2], true, &(v.orientation));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!try_str_to_byte(arr[3], &(v.fov)) || 180 < v.fov)
		return (LOAD_ERR_VAL_OUT_OF_RANGE);
	scene->is_camera_set = true;
	scene->camera = v;
	return (LOAD_ERR_SUCCESS);
}
