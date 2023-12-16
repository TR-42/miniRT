/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:16:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 19:58:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include <utils.h>

#include "_rt_loader.h"

#define ELEM_CNT 3

static void	_normalize_chk(
	const bool *force_normalize,
	t_vec3 *dst,
	t_lderr *err
)
{
	if (force_normalize == NULL)
		return ;
	if (*force_normalize)
		*dst = vec3_normalize(*dst);
	else if (vec3_len(*dst) != 1)
		*err = LOAD_ERR_NRM_VEC_LEN_NOT_1;
	if (vec3_len(*dst) == 0)
		*err = LOAD_ERR_NRM_VEC_LEN_ZERO;
}

__attribute__((nonnull(1, 3)))
t_lderr	_parse_vec3(
	const char *input,
	bool *force_normalize,
	t_vec3 *dst,
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
		*err = perr_retint("_parse_vec3/ft_split", LOAD_ERR_PRINTED);
	else if (arrlen2d((void *)arr2d) != ELEM_CNT)
		*err = LOAD_ERR_TOO_FEW_PARAMS;
	else if (!try_strtod(arr2d[0], NULL, &(dst->x))
		|| !try_strtod(arr2d[1], NULL, &(dst->y))
		|| !try_strtod(arr2d[2], NULL, &(dst->z)))
		*err = LOAD_ERR_NOT_A_NUMBER;
	_normalize_chk(force_normalize, dst, err);
	free2darr((void **)arr2d);
	return (*err);
}
