/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 11:53:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 4

__attribute__((nonnull))
t_plane	_load_plane(
	char *const arr[],
	t_lderr *err
)
{
	t_plane	v;

	v = (t_plane){0};
	v.comm.type = T_OBJ_PLANE;
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], false, &(v.center), err) == LOAD_ERR_SUCCESS
		&& _parse_vec3(arr[2], true, &(v.orientation), err) == LOAD_ERR_SUCCESS)
		_parse_rgb(arr[3], &(v.color), err);
	return (v);
}
