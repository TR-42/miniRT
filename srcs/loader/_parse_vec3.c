/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:16:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 00:23:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 3

static bool	_is_normalized(double v)
{
	return (-1 <= v && v <= 1);
}

__attribute__((nonnull))
t_lderr	_parse_vec3(
	const char *input,
	bool is_normalized,
	t_vec3 *dst
)
{
	t_lderr	err;
	char	**arr2d;

	err = LOAD_ERR_SUCCESS;
	arr2d = ft_split(input, ',');
	if (arr2d == NULL)
		return (perr_retint("_parse_vec3/ft_split", LOAD_ERR_PRINTED));
	if (arrlen2d((void *)arr2d) != ELEM_CNT)
		err = LOAD_ERR_TOO_FEW_PARAMS;
	if (!try_strtod(arr2d[0], NULL, &(dst->x))
		|| !try_strtod(arr2d[1], NULL, &(dst->y))
		|| !try_strtod(arr2d[2], NULL, &(dst->z)))
		err = LOAD_ERR_NOT_A_NUMBER;
	if (is_normalized && !(
			_is_normalized(dst->x)
			&& _is_normalized(dst->y)
			&& _is_normalized(dst->x)
		)
	)
		err = LOAD_ERR_VAL_OUT_OF_RANGE;
	free2darr((void **)arr2d);
	return (err);
}
