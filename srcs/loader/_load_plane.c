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
t_lderr	_load_plane(
	char *const arr[],
	t_scene *scene
)
{
	t_lderr	err;
	t_objs	obj;
	t_plane	*v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	obj = (t_objs){0};
	v = &(obj.plane);
	err = _parse_vec3(arr[1], false, &(v->center));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	err = _parse_vec3(arr[2], true, &(v->orientation));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	err = _parse_rgb(arr[3], &(v->color));
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!vect_push_back(&(scene->objs), &obj, NULL))
		return (errstr_retint(
				"load_plane", "push_back failed", LOAD_ERR_PRINTED));
	return (LOAD_ERR_SUCCESS);
}
