/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:50:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/08 19:51:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <canvas.h>
#include <print_inline_img.h>
#include <utils.h>

#define CANVAS_HEIGHT 480
#define CANVAS_WIDTH 640

static void	_set_gradient(
	t_cnvas *canvas
)
{
	int		ix;
	int		iy;
	t_rgb	color;

	iy = 0;
	color.b = 0.5 * 256;
	while (iy < CANVAS_HEIGHT)
	{
		ix = 0;
		color.g = ((double)iy / CANVAS_HEIGHT) * 256;
		while (ix < CANVAS_WIDTH)
		{
			color.r = ((double)ix / CANVAS_WIDTH) * 256;
			canvas_set_color(canvas, ix, iy, color);
			ix += 1;
		}
		iy += 1;
	}
}

int	main(
	int argc,
	const char *argv[]
)
{
	t_cnvas	canvas;
	t_byte	*tmp;
	size_t	len;
	int		ret;

	(void)argc;
	(void)argv;
	if (!canvas_init(&canvas, CANVAS_HEIGHT, CANVAS_WIDTH))
		return (perr_retint("canvas_init", 1));
	_set_gradient(&canvas);
	tmp = NULL;
	len = canvas_to_png(&canvas, &tmp);
	canvas_dispose(&canvas);
	ret = print_inline_img(tmp, len);
	if (!ret)
		perr_retint("print_inline_img", 0);
	free(tmp);
	return (!ret);
}
