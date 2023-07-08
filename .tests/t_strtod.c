/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strtod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:33:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 01:48:33 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils.h>

#define FORMAT_STR "'%10s' => %lf (len:%lu)\n"

int	main(int argc, const char *argv[])
{
	size_t	i;
	double	value;
	char	*endptr;

	i = 0;
	while (++i < (size_t)argc)
	{
		if (i != 1)
			putc('\n', stdout);
		value = ft_strtod(argv[i], &endptr);
		printf(FORMAT_STR, argv[i], value, endptr - argv[i]);
		value = strtod(argv[i], &endptr);
		printf(FORMAT_STR, "(original)", value, endptr - argv[i]);
	}
	return (0);
}
