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

#include <ft_mem/ft_mem.h>

#include <utils.h>

#include "_rt_loader.h"
#include <sphere.h>

#define ELEM_CNT 4

__attribute__((nonnull))
t_spher	_load_sphere(
	char *const arr[],
	t_lderr *err
)
{
	t_spher	v;

	ft_bzero(&v, sizeof(t_spher));
	v.comm.type = T_OBJ_SPHERE;
	if (arrlen2d((void *)arr) != ELEM_CNT)
		*err = LOAD_ERR_INVAL_ARGS_COUNT;
	else if (_parse_vec3(arr[1], false, &(v.center), err) == LOAD_ERR_SUCCESS
		&& !try_strtod(arr[2], NULL, &(v.diameter)))
		*err = LOAD_ERR_NOT_A_NUMBER;
	else
		_parse_rgb(arr[3], &(v.color), err);
	sphere_init_f(&v);
	return (v);
}
