/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_str_to_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:29:23 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 00:32:24 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_is/ft_is.h>

#include <utils.h>

__attribute__((nonnull))
bool	try_str_to_byte(
	const char *str,
	unsigned char *dst
)
{
	unsigned int	v;

	if (!ft_isdigit(*str))
		return (false);
	v = *str - '0';
	if (*str == '0')
		while (*str == '0')
			str += 1;
	else
		str += 1;
	if (ft_isdigit(*str))
		v = (v * 10) + (*str++ - '0');
	if (ft_isdigit(*str))
		v = (v * 10) + (*str++ - '0');
	*dst = (unsigned char)v;
	return (v < 256);
}
