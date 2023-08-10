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

	dst = canvas->buf + ((y * canvas->width) + x) * 4;
	dst[3] = 255;
	dst[0] = color.r;
	dst[1] = color.g;
	dst[2] = color.b;
}
