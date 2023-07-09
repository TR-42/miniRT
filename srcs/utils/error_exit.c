/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:10:46 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 22:57:52 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - perror
#include <stdio.h>

// - exit
#include <stdlib.h>

// - strerror
#include <string.h>

// - write
#include <unistd.h>

#include <ft_put/ft_put.h>
#include <ft_string/ft_string.h>

#include <utils.h>

__attribute__((noreturn))
void	perr_exit(
	const char *str
)
{
	strerr_exit(str, errno);
}

__attribute__((noreturn))
void	strerr_exit(
	const char *str,
	int _errno
)
{
	errstr_exit(str, strerror(_errno));
}

__attribute__((noreturn))
void	errstr_exit(
	const char *str,
	const char *msg
)
{
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	if (msg != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		ft_putendl_fd(msg, STDERR_FILENO);
	}
	exit(1);
}
