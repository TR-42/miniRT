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
t_cam	_load_camera(
	char *const arr[],
	t_lderr *err
)
{
	t_cam	v;

	v = (t_cam){0};
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], false, &(v.point), err) == LOAD_ERR_SUCCESS
		&& _parse_vec3(arr[2], true, &(v.orientation), err) == LOAD_ERR_SUCCESS
		&& (!try_str_to_byte(arr[3], &(v.fov)) || 180 < v.fov))
		*err = LOAD_ERR_VAL_OUT_OF_RANGE;
	return (v);
}
