/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 20:07:07 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem/ft_mem.h>

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 4

__attribute__((nonnull))
t_cam	_load_camera(
	char *const arr[],
	bool force_normalize,
	t_lderr *err
)
{
	t_cam	v;

	ft_bzero(&v, sizeof(t_cam));
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], NULL, &(v.point), err) == LOAD_ERR_SUCCESS
		&& _parse_vec3(arr[2], &force_normalize,
			&(v.orientation), err) == LOAD_ERR_SUCCESS
		&& (!try_strtod(arr[3], NULL, &(v.fov)) || v.fov < 0 || 180 < v.fov))
		*err = LOAD_ERR_VAL_OUT_OF_RANGE;
	return (v);
}
