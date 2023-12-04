/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:43:41 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/02 00:25:51 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <stddef.h>
# include <stdint.h>
# include "rt_types.h"

# define CANVAS_PIX_R 0
# define CANVAS_PIX_G 1
# define CANVAS_PIX_B 2
# define CANVAS_PIX_A 3
# define CANVAS_PIX_SIZE 4

typedef struct s_cnvas
{
	int		height;
	int		width;
	uint8_t	*buf;
}	t_cnvas;

bool	canvas_init(
			t_cnvas *dst,
			int height,
			int width
			)
		__attribute__((nonnull))
		;

bool	canvas_dispose(
			t_cnvas *canvas
			)
		__attribute__((nonnull))
		;

void	canvas_set_color(
			t_cnvas *canvas,
			size_t x,
			size_t y,
			t_rgb color
			)
		__attribute__((nonnull))
		;

size_t	canvas_to_png(
			t_cnvas *canvas,
			t_byte **dst
			)
		__attribute__((nonnull))
		;

#endif
