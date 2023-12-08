/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ignore_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:25:36 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/07 23:43:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "_rt_loader.h"

__attribute__((nonnull))
static bool	_is_comment(const char *line)
{
	return (line[0] == '#');
}

void	_ignore_comment(char **arr)
{
	size_t	i;

	if (arr == NULL || arr[0] == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL && !_is_comment(arr[i]))
		i++;
	while (arr[i] != NULL)
	{
		free((void *)arr[i]);
		arr[i++] = NULL;
	}
}
