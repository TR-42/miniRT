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

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 3

__attribute__((nonnull))
t_lderr	_load_amb_light(
	char *const arr[],
	t_scene *scene
)
{
	t_lderr		err;
	t_amb_light	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		return (LOAD_ERR_TOO_FEW_ARGS);
	v = (t_amb_light){0};
	if (!try_strtod(arr[1], NULL, &(v.ratio)))
		return (LOAD_ERR_NOT_A_NUMBER);
	if (v.ratio < 0 || 1 < v.ratio)
		return (LOAD_ERR_VAL_OUT_OF_RANGE);
	err = _parse_rgb(arr[2], &(v.color));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	scene->is_amb_l_set = true;
	scene->amb_light = v;
	return (LOAD_ERR_SUCCESS);
}
