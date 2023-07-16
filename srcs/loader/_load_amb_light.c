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
void	_load_amb_light(
	char *const arr[],
	t_scene *scene
)
{
	t_amb_light	v;

	if (arrlen2d((void *)arr) != ELEM_CNT)
		_err_too_few_param_exit();
	v = (t_amb_light){0};
	if (!try_strtod(arr[1], NULL, &(v.ratio)))
		_err_notnum_exit();
	if (v.ratio < 0 || 1 < v.ratio)
		_err_val_out_of_range_exit();
	v.color = _parse_rgb(arr[2]);
	scene->is_amb_l_set = true;
	scene->amb_light = v;
}
