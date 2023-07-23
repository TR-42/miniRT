/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_strtod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:32:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/16 23:48:24 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_is/ft_is.h>

#include <utils.h>

bool	try_strtod(
	const char *str,
	char **endptr,
	double *dst
)
{
	bool	_num;
	bool	_point;
	size_t	i;

	if (str == NULL)
		return (false);
	_num = ft_isdigit(*str);
	_point = *str == '.';
	if (!_num && !_point && !(*str == '-' || *str == '+'))
		return (false);
	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '.' && !_point)
			_point = true;
		else if (str[i] == '.' || !ft_isdigit(str[i]))
			return (false);
		_num = (_num || ft_isdigit(str[i]));
	}
	if (_num && dst != NULL)
		*dst = ft_strtod(str, endptr);
	return (_num);
}
