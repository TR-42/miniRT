/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 11:29:36 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 4

__attribute__((nonnull))
t_light	_load_light(
	char *const arr[],
	t_lderr *err
)
{
	t_light	v;

	v = (t_light){0};
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], false, &(v.point), err) == LOAD_ERR_SUCCESS
		&& !try_strtod(arr[2], NULL, &(v.brightness)))
		*err = LOAD_ERR_NOT_A_NUMBER;
	else if ((v.brightness < 0 || 1 < v.brightness))
		*err = LOAD_ERR_VAL_OUT_OF_RANGE;
	else
		_parse_rgb(arr[3], &(v.color), err);
	return (v);
}
