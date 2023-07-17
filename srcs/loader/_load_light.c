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
t_lderr	_load_light(
	char *const arr[],
	t_scene *scene
)
{
	t_lderr	err;
	t_light	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		return (LOAD_ERR_TOO_FEW_ARGS);
	v = (t_light){0};
	err = _parse_vec3(arr[1], false, &(v.point));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!try_strtod(arr[2], NULL, &(v.brightness)))
		return (LOAD_ERR_NOT_A_NUMBER);
	if (v.brightness < 0 || 1 < v.brightness)
		return (LOAD_ERR_VAL_OUT_OF_RANGE);
	err = _parse_rgb(arr[3], &(v.color));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	scene->is_light_set = true;
	scene->light = v;
	return (LOAD_ERR_SUCCESS);
}
