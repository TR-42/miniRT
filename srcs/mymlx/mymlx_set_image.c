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
	unsigned char *dst,
	int y
)
{
	t_byte	*src;
	int		x;

	x = 0;
	src = canvas->buf + y * canvas->width * 4;
	dst += y * mymlx->line_length;
	while (x < canvas->width)
	{
		dst[0] = src[0];
		dst[1] = src[1];
		dst[2] = src[2];
		dst += mymlx->bpp / 8;
		src += 4;
		x++;
	}
}

// imgがNULLな場合はここに来る可能性がない
__attribute__((nonnull))
void	mymlx_set_image(
	t_mymlx *mymlx,
	const t_cnvas *canvas
)
{
	unsigned char	*img;
	int				y;

	img = (unsigned char *)mlx_get_data_addr(
			mymlx->img,
			&(mymlx->bpp),
			&(mymlx->line_length),
			&(mymlx->endian)
			);
	y = 0;
	while (y < canvas->height)
		_set_img_pixel_row(mymlx, canvas, img, y++);
	mlx_put_image_to_window(mymlx->mlx, mymlx->win, mymlx->img, 0, 0);
}
