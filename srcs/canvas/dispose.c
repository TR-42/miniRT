/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:18:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/02 00:19:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_mem/ft_mem.h>

#include <canvas.h>

__attribute__((nonnull))
bool	canvas_dispose(
	t_cnvas *canvas
)
{
	if (canvas->buf != NULL)
		free(canvas->buf);
	ft_bzero(canvas, sizeof(t_cnvas));
	return (true);
}
