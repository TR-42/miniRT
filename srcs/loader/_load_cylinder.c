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
void	_load_cylinder(
	char *const arr[],
	t_scene *scene
)
{
	t_objs	obj;
	t_cylnd	*v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	obj = (t_objs){0};
	v = &(obj.cylinder);
	v->center = _parse_vec3(arr[1], false);
	v->axis = _parse_vec3(arr[2], true);
	if (!try_strtod(arr[3], NULL, &(v->diameter))
		|| !try_strtod(arr[4], NULL, &(v->height)))
		_err_notnum_exit();
	v->color = _parse_rgb(arr[5]);
	if (!vect_push_back(&(scene->objs), &obj, NULL))
		errstr_exit("load_cylinder", "push_back failed");
}
