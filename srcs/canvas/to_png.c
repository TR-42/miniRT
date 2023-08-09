/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_png.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:08:47 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/10 01:41:26 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <canvas.h>

#ifdef ENABLE_PNG

# include <stdlib.h>
# include <png.h>

# include <ft_vect/ft_vect.h>

static void	_my_png_write_callback(
	png_structp p_png,
	png_bytep data,
	png_size_t length
)
{
	t_vect	*vect;

	vect = (t_vect *)png_get_io_ptr(p_png);
	if (vect->p == NULL)
		return ;
	if (!vect_append_range(vect, data, length))
		vect_dispose(vect);
}

static size_t	_call_write_fn(
	png_structp p_png,
	png_infop p_info,
	t_byte **dst
)
{
	t_vect	vect;

	vect = vect_init(4096, sizeof(t_byte));
	if (vect.p == NULL)
		return (0);
	png_set_write_fn(p_png, &vect, _my_png_write_callback, NULL);
	png_write_png(p_png, p_info, PNG_TRANSFORM_IDENTITY, NULL);
	if (vect.p == NULL)
		return (0);
	*dst = (t_byte *)(vect.p);
	return (vect.len);
}

// ref: https://daeudaeu.com/libpng/
// ref: https://gist.github.com/dobrokot/10486786
__attribute__((nonnull))
size_t	canvas_to_png(
	t_cnvas *canvas,
	t_byte **dst
)
{
	png_structp	p_png;
	png_infop	p_info;
	t_byte		**rows;
	size_t		iy;

	p_png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	p_info = png_create_info_struct(p_png);
	png_set_IHDR(p_png, p_info, canvas->width, canvas->height, 8,
		PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	rows = malloc(sizeof(t_byte *) * canvas->height);
	iy = 0;
	if (rows != NULL)
	{
		while (iy++ < (size_t)(canvas->height))
			rows[iy - 1] = canvas->buf + ((iy - 1) * canvas->width * 4);
		png_set_rows(p_png, p_info, rows);
		iy = _call_write_fn(p_png, p_info, dst);
		free(rows);
	}
	png_destroy_write_struct(&p_png, &p_info);
	return (iy);
}

#else

__attribute__((nonnull))
size_t	canvas_to_png(
	t_cnvas *canvas,
	t_byte **dst
)
{
	(void)canvas;
	*dst = NULL;
	return (0);
}

#endif
