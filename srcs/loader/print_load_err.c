/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_load_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 01:09:12 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/21 01:20:14 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt_loader.h>
#include <utils.h>

#define ERR_MSG_DUP_DEF "multiple definition of A, C, or L"
#define ERR_MSG_UNKNOWN_TYPE_ID "unknown type id"
#define ERR_MSG_NOT_A_NUMBER "not a number"
#define ERR_MSG_VAL_OUT_OF_RANGE "value out of range"
#define ERR_MSG_INVAL_ARGS_COUNT "invalid arguments length"
#define ERR_MSG_TOO_FEW_PARAMS "too few parameters"
#define ERR_MSG_NO_CAMERA "camera is missing"

static void	_print(const char *const msg)
{
	errstr_retint("load RT file", msg, 0);
}

void	print_load_err(t_lderr err)
{
	if (err == LOAD_ERR_SUCCESS || err == LOAD_ERR_PRINTED)
		return ;
	else if (err == LOAD_ERR_DUP_DEF)
		_print(ERR_MSG_DUP_DEF);
	else if (err == LOAD_ERR_UNKNOWN_TYPE_ID)
		_print(ERR_MSG_UNKNOWN_TYPE_ID);
	else if (err == LOAD_ERR_NOT_A_NUMBER)
		_print(ERR_MSG_NOT_A_NUMBER);
	else if (err == LOAD_ERR_INVAL_ARGS_COUNT)
		_print(ERR_MSG_INVAL_ARGS_COUNT);
	else if (err == LOAD_ERR_TOO_FEW_PARAMS)
		_print(ERR_MSG_NO_CAMERA);
}
