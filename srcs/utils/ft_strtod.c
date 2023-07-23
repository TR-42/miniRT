/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:45:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 01:56:14 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#include <utils.h>

#include "ft_is/ft_is.h"

static bool	set_sign(
	const char **str,
	char *sign
)
{
	*sign = 1;
	if (**str == '-')
		*sign = -1;
	if (**str == '+' || **str == '-')
		*str += 1;
	else
		return (false);
	return (true);
}

static bool	set_int(
	const char **str,
	double *value
)
{
	if (!ft_isdigit(**str))
		return (false);
	*value = 0;
	while (ft_isdigit(**str))
	{
		*value = (*value * 10) + (**str - '0');
		*str += 1;
	}
	return (true);
}

static double	get_dec_value(
	char _v,
	size_t i_target
)
{
	double	v;
	size_t	i;

	v = (double)_v;
	i = 0;
	while (i++ < i_target)
		v *= 0.1;
	return (v);
}

static bool	set_dec(
	const char **str,
	double *value,
	bool is_int_set
)
{
	size_t	i;

	if (**str != '.' || (!is_int_set && !ft_isdigit(*(*str + 1))))
		return (false);
	*str += 1;
	i = 1;
	while (ft_isdigit(**str))
	{
		*value += get_dec_value(**str - '0', i++);
		*str += 1;
	}
	return (true);
}

double	ft_strtod(
	const char *str,
	char **endptr
)
{
	char	sign;
	double	value;
	bool	is_int_set;

	if (endptr != NULL)
		*endptr = (char *)str;
	if (str == NULL)
		return (NAN);
	while (*str != '\0' && ft_isspace(*str))
		str++;
	set_sign(&str, &sign);
	value = 0;
	is_int_set = set_int(&str, &value);
	set_dec(&str, &value, is_int_set);
	if (endptr != NULL)
		*endptr = (char *)str;
	return (value * sign);
}
