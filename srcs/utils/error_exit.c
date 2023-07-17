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

// - exit
#include <stdlib.h>

#include <utils.h>

__attribute__((noreturn))
void	perr_exit(
	const char *str
)
{
	exit(perr_retint(str, 1));
}

__attribute__((noreturn))
void	strerr_exit(
	const char *str,
	int _errno
)
{
	exit(strerr_retint(str, _errno, 1));
}

__attribute__((noreturn))
void	errstr_exit(
	const char *str,
	const char *msg
)
{
	exit(errstr_retint(str, msg, 1));
}
