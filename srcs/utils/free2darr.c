/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2darr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:13:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 23:16:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <utils.h>

void	*free2darr(
	void **arr2d
)
{
	size_t	i;

	if (arr2d == NULL)
		return (NULL);
	i = 0;
	while (arr2d[i] != NULL)
		free(arr2d[i++]);
	free(arr2d);
	return (NULL);
}
