/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 20:00:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem/ft_mem.h>

#include <utils.h>

#include "_rt_loader.h"
#include <plane.h>

#define ELEM_CNT 4

__attribute__((nonnull))
t_plane	_load_plane(
	char *const arr[],
	bool force_normalize,
	t_lderr *err
)
{
	t_plane	v;

	ft_bzero(&v, sizeof(t_plane));
	v.comm.type = T_OBJ_PLANE;
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], NULL, &(v.point), err) == LOAD_ERR_SUCCESS
		&& _parse_vec3(arr[2], &force_normalize,
			&(v.orientation), err) == LOAD_ERR_SUCCESS)
		_parse_rgb(arr[3], &(v.color), err);
	plane_init_f(&v);
	return (v);
}
