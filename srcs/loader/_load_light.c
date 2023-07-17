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
void	_load_light(
	char *const arr[],
	t_scene *scene
)
{
	t_light	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	v = (t_light){0};
	v.point = _parse_vec3(arr[1], false);
	if (!try_strtod(arr[2], NULL, &(v.brightness)))
		_err_notnum_exit();
	if (v.brightness < 0 || 1 < v.brightness)
		_err_val_out_of_range_exit();
	v.color = _parse_rgb(arr[3]);
	scene->is_light_set = true;
	scene->light = v;
}
