/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:19:41 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 00:38:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 3

__attribute__((nonnull))
t_rgb	_parse_rgb(
	const char *input
)
{
	char	**arr2d;
	t_rgb	rgb;

	arr2d = ft_split(input, ',');
	if (arrlen2d((void *)arr2d) != ELEM_CNT)
		_err_too_few_param_exit();
	if (!try_str_to_byte(arr2d[0], &(rgb.r))
		|| !try_str_to_byte(arr2d[1], &(rgb.g))
		|| !try_str_to_byte(arr2d[2], &(rgb.b)))
		_err_notnum_exit();
	free2darr((void **)arr2d);
	return (rgb);
}
