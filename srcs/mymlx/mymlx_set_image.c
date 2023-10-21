/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_set_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:50:33 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:28:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mymlx.h>

// TODO: 色の順番が違う
// TODO: bppが異なるかもしれない
__attribute__((nonnull))
void	_set_img_pixel_row(
	const t_mymlx *mymlx,
	const t_cnvas *canvas,
	const t_byte *src,
	t_byte *dst
)
{
	int	x;

	x = 0;
	while (x++ < canvas->width)
	{
		if (mymlx->endian == 0)
		{
			dst[0] = src[CANVAS_PIX_B];
			dst[1] = src[CANVAS_PIX_G];
			dst[2] = src[CANVAS_PIX_R];
			dst[3] = src[CANVAS_PIX_A];
		}
		else
		{
			dst[0] = src[CANVAS_PIX_A];
			dst[1] = src[CANVAS_PIX_R];
			dst[2] = src[CANVAS_PIX_G];
			dst[3] = src[CANVAS_PIX_B];
		}
		dst += mymlx->bpp / 8;
		src += CANVAS_PIX_SIZE;
	}
}

// imgがNULLな場合はここに来る可能性がない
__attribute__((nonnull))
void	mymlx_set_image(
	t_mymlx *mymlx,
	const t_cnvas *canvas
)
{
	int				y;

	y = 0;
	while (y < canvas->height)
	{
		_set_img_pixel_row(
			mymlx,
			canvas,
			canvas->buf + (y * canvas->width * 4),
			mymlx->img_d + (y * mymlx->line_length)
			)
		;
		y += 1;
	}
	mlx_put_image_to_window(mymlx->mlx, mymlx->win, mymlx->img, 0, 0);
}
