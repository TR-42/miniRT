/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_retint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:35:41 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 19:44:34 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - perror
#include <stdio.h>

// - strerror
#include <string.h>

// - write
#include <unistd.h>

#include <ft_put/ft_put.h>
#include <ft_string/ft_string.h>

#include <utils.h>

#define ERROR_STR "Error\n"

int	perr_retint(
	const char *str,
	int ret
)
{
	return (strerr_retint(str, errno, ret));
}

int	strerr_retint(
	const char *str,
	int _errno,
	int ret
)
{
	return (errstr_retint(str, strerror(_errno), ret));
}

int	errstr_retint(
	const char *str,
	const char *msg,
	int ret
)
{
	write(STDERR_FILENO, ERROR_STR, sizeof(ERROR_STR) - 1);
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	if (msg != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		ft_putendl_fd(msg, STDERR_FILENO);
	}
	return (ret);
}
