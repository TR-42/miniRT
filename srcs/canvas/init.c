/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:10:39 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/02 00:19:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem/ft_mem.h>

#include <canvas.h>

__attribute__((nonnull))
bool	canvas_init(
	t_cnvas *dst,
	int height,
	int width
)
{
	ft_bzero(dst, sizeof(t_cnvas));
	dst->buf = ft_calloc(CANVAS_PIX_SIZE, (size_t)width * (size_t)height);
	if (dst->buf == NULL)
		return (false);
	dst->height = height;
	dst->width = width;
	return (true);
}
