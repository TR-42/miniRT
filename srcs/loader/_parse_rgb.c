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

__attribute__((nonnull(1, 2)))
t_lderr	_parse_rgb(
	const char *input,
	t_rgb *dst,
	t_lderr *err
)
{
	t_lderr	_err;
	char	**arr2d;

	if (err == NULL)
		err = &_err;
	*err = LOAD_ERR_SUCCESS;
	arr2d = ft_split(input, ',');
	if (arr2d == NULL)
		*err = perr_retint("_parse_rgb/ft_split", LOAD_ERR_PRINTED);
	else if (arrlen2d((void *)arr2d) != ELEM_CNT)
		*err = LOAD_ERR_TOO_FEW_PARAMS;
	else if (!try_str_to_byte(arr2d[0], &(dst->r))
		|| !try_str_to_byte(arr2d[1], &(dst->g))
		|| !try_str_to_byte(arr2d[2], &(dst->b)))
		*err = LOAD_ERR_NOT_A_NUMBER;
	free2darr((void **)arr2d);
	return (*err);
}
