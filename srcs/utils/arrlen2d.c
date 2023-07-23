/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlen2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:10:02 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/16 23:13:11 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

size_t	arrlen2d(
	const void *const *arr2d
)
{
	size_t	i;

	if (arr2d == NULL)
		return (0);
	i = 0;
	while (*arr2d++ != NULL)
		i += 1;
	return (i);
}
