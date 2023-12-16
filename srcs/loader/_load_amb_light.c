/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 00:35:09 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem/ft_mem.h>

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 3

__attribute__((nonnull))
t_amb_light	_load_amb_light(
	char *const arr[],
	t_lderr *err
)
{
	t_amb_light	v;

	ft_bzero(&v, sizeof(t_amb_light));
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (!try_strtod(arr[1], NULL, &(v.ratio)))
		*err = LOAD_ERR_NOT_A_NUMBER;
	else if (v.ratio < 0 || 1 < v.ratio)
		*err = LOAD_ERR_VAL_OUT_OF_RANGE;
	else
		_parse_rgb(arr[2], &(v.color), err);
	return (v);
}
