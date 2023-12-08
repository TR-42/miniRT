/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_lderr_str.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:11:22 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:26:20 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_LDERR_STR_H
# define _GET_LDERR_STR_H

# include <rt_loader.h>

# define IF_RET_ERR_STR(_err) \
if (err == _err)\
	return (#_err);

static const char	*_get_lderr_str(t_lderr err)
{
	IF_RET_ERR_STR(LOAD_ERR_SUCCESS)
	else IF_RET_ERR_STR(LOAD_ERR_PRINTED)
	else IF_RET_ERR_STR(LOAD_ERR_DUP_DEF)
	else IF_RET_ERR_STR(LOAD_ERR_UNKNOWN_TYPE_ID)
	else IF_RET_ERR_STR(LOAD_ERR_NOT_A_NUMBER)
	else IF_RET_ERR_STR(LOAD_ERR_VAL_OUT_OF_RANGE)
	else IF_RET_ERR_STR(LOAD_ERR_INVAL_ARGS_COUNT)
	else IF_RET_ERR_STR(LOAD_ERR_TOO_FEW_PARAMS)
	else IF_RET_ERR_STR(LOAD_ERR_NO_CAMERA)
	else IF_RET_ERR_STR(LOAD_ERR_NRM_VEC_LEN_ZERO)
	else
		return ("(Unknown load_error id)");
}

#endif