/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 11:51:15 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem/ft_mem.h>

#include <utils.h>

#include <cylinder.h>
#include "_rt_loader.h"

#define ELEM_CNT 6

__attribute__((nonnull))
t_cylnd	_load_cylinder(
	char *const arr[],
	t_lderr *err
)
{
	t_cylnd	v;

	ft_bzero(&v, sizeof(t_cylnd));
	v.comm.type = T_OBJ_CYLINDER;
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], false, &(v.center), err) == LOAD_ERR_SUCCESS
		&& _parse_vec3(arr[2], true, &(v.axis), err) == LOAD_ERR_SUCCESS
		&& (!try_strtod(arr[3], NULL, &(v.diameter))
			|| !try_strtod(arr[4], NULL, &(v.height))))
		*err = LOAD_ERR_NOT_A_NUMBER;
	else if (v.diameter <= 0 || v.height <= 0)
		*err = LOAD_ERR_VAL_OUT_OF_RANGE;
	else
		_parse_rgb(arr[5], &(v.color), err);
	cylinder_init_f(&v);
	return (v);
}
