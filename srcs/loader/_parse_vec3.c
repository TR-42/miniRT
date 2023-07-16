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
t_vec3	_parse_vec3(
	const char *input,
	bool is_normalized
)
{
	char	**arr2d;
	t_vec3	ret;

	arr2d = ft_split(input, ',');
	if (arrlen2d((void *)arr2d) != ELEM_CNT)
		_err_too_few_param_exit();
	if (!try_strtod(arr2d[0], NULL, &(ret.x))
		|| !try_strtod(arr2d[1], NULL, &(ret.y))
		|| !try_strtod(arr2d[2], NULL, &(ret.z)))
		_err_notnum_exit();
	if (is_normalized && !(
			_is_normalized(ret.x)
			&& _is_normalized(ret.y)
			&& _is_normalized(ret.x)
		)
	)
		_err_val_out_of_range_exit();
	free2darr((void **)arr2d);
	return (ret);
}
