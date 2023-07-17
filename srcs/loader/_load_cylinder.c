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

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 6

__attribute__((nonnull))
t_lderr	_load_cylinder(
	char *const arr[],
	t_scene *scene
)
{
	t_lderr	err;
	t_objs	obj;
	t_cylnd	*v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		return (LOAD_ERR_TOO_FEW_ARGS);
	obj = (t_objs){0};
	v = &(obj.cylinder);
	err = _parse_vec3(arr[1], false, &(v->center));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	err = _parse_vec3(arr[2], true, &(v->axis));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!try_strtod(arr[3], NULL, &(v->diameter))
		|| !try_strtod(arr[4], NULL, &(v->height)))
		return (LOAD_ERR_NOT_A_NUMBER);
	err = _parse_rgb(arr[5], &(v->color));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!vect_push_back(&(scene->objs), &obj, NULL))
		return (errstr_retint(
				"load_cylinder", "push_back failed", LOAD_ERR_PRINTED));
	return (LOAD_ERR_SUCCESS);
}
