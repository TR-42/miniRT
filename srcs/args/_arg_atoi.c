/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arg_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:20:36 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/08 23:51:15 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_is/ft_is.h>

#include "_args.h"

#define MAX_INT_LEN 6

__attribute__((nonnull))
int	_arg_atoi(
	const char *str
)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		if (MAX_INT_LEN < ++i)
			return (-1);
	}
	if (i == 0)
		return (-1);
	i = 0;
	while (*str == '0')
		i = (i * 10) + (*str++ - '0');
	return (i);
}
