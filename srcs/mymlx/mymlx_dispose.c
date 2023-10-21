/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_dispose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:46:57 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:28:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mymlx.h>

__attribute__((nonnull))
bool	mymlx_dispose(t_mymlx *mymlx)
{
	if (mymlx->img != NULL)
	{
		mlx_destroy_image(mymlx->mlx, mymlx->img);
		mymlx->img = NULL;
	}
	if (mymlx->win != NULL)
	{
		mlx_destroy_window(mymlx->mlx, mymlx->win);
		mymlx->win = NULL;
	}
	if (mymlx->mlx != NULL)
	{
		mlx_destroy_display(mymlx->mlx);
		free(mymlx->mlx);
		mymlx->mlx = NULL;
	}
	return (true);
}
