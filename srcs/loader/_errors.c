/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _errors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:57:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/16 23:18:02 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - exit
#include <stdlib.h>

// - write
#include <unistd.h>

#include "_rt_loader.h"

#define ERR_NOT_NUM "miniRT: Invalid RT Input (not a valid number format)"
#define ERR_VAL_OUT_OF_RANGE "miniRT: Invalid RT Input (value out of range)"
#define ERR_TOO_FEW_PARAM "miniRT: Invalid RT Input (too few params)"

__attribute__((noreturn))
void	_err_notnum_exit(void)
{
	write(
		STDERR_FILENO,
		ERR_NOT_NUM,
		sizeof(ERR_NOT_NUM) - 1);
	exit(1);
}

__attribute__((noreturn))
void	_err_val_out_of_range_exit(void)
{
	write(
		STDERR_FILENO,
		ERR_VAL_OUT_OF_RANGE,
		sizeof(ERR_VAL_OUT_OF_RANGE) - 1);
	exit(1);
}

__attribute__((noreturn))
void	_err_too_few_param_exit(void)
{
	write(
		STDERR_FILENO,
		ERR_TOO_FEW_PARAM,
		sizeof(ERR_TOO_FEW_PARAM) - 1);
	exit(1);
}
