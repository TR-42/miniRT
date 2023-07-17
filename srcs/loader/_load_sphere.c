/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _load_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:40:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 11:55:21 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 4

__attribute__((nonnull))
void	_load_sphere(
	char *const arr[],
	t_scene *scene
)
{
	t_objs	obj;
	t_spher	*v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	obj = (t_objs){0};
	v = &(obj.sphere);
	v->center = _parse_vec3(arr[1], false);
	if (!try_strtod(arr[2], NULL, &(v->diameter)))
		_err_notnum_exit();
	v->color = _parse_rgb(arr[3]);
	if (!vect_push_back(&(scene->objs), &obj, NULL))
		errstr_exit("load_sphere", "push_back failed");
}
