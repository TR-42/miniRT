/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:22:23 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/08 23:26:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

__attribute__((nonnull))
void	canvas_set_color(
	t_cnvas *canvas,
	size_t x,
	size_t y,
	t_rgb color
)
{
	t_byte	*dst;

	dst = canvas->buf + ((y * canvas->width) + x) * CANVAS_PIX_SIZE;
	dst[CANVAS_PIX_A] = 255;
	dst[CANVAS_PIX_R] = color.r;
	dst[CANVAS_PIX_G] = color.g;
	dst[CANVAS_PIX_B] = color.b;
}
