/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:19:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/02 00:53:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_math/ft_math.h>
#include <ft_mem/ft_mem.h>

#include <canvas.h>

#define BMP_FILEHEADER_LEN 14
#define BMP_HEADER_INFO_LEN 40
#define BMP_PLANE_COUNT 1
#define BMP_BYTE_PER_PIXEL 24
#define BMP_COMPRESSION_TYPE 0
#define BMP_SIZE_IMAGE 0
#define BMP_PIXEL_PER_METER_X 0
#define BMP_PIXEL_PER_METER_Y 0
#define BMP_COLORS_USED 0
#define BMP_IMPORTANT_COLOR_INDEX 0

__attribute__((nonnull))
static void	_set_fileheader(
	uint8_t *dst,
	size_t filesize
)
{
	dst[0] = 'B';
	dst[1] = 'M';
	if (UINT32_MAX < filesize)
		filesize = 0;
	*(uint32_t *)(dst + 2) = filesize;
	*(uint32_t *)(dst + 6) = 0;
	*(uint32_t *)(dst + 10) = BMP_FILEHEADER_LEN + BMP_HEADER_INFO_LEN;
}

__attribute__((nonnull))
static void	_set_header_info(
	uint8_t *dst,
	int height,
	int width
)
{
	*(uint32_t *)(dst + 0) = 40;
	*(uint32_t *)(dst + 4) = width;
	*(uint32_t *)(dst + 8) = height;
	*(uint16_t *)(dst + 12) = BMP_PLANE_COUNT;
	*(uint16_t *)(dst + 14) = BMP_BYTE_PER_PIXEL * 8;
	*(uint32_t *)(dst + 16) = BMP_COMPRESSION_TYPE;
	*(uint32_t *)(dst + 20) = BMP_SIZE_IMAGE;
	*(uint32_t *)(dst + 24) = BMP_PIXEL_PER_METER_X;
	*(uint32_t *)(dst + 28) = BMP_PIXEL_PER_METER_Y;
	*(uint32_t *)(dst + 32) = BMP_COLORS_USED;
	*(uint32_t *)(dst + 36) = BMP_IMPORTANT_COLOR_INDEX;
}

__attribute__((nonnull))
static void	_set_pixels(
	const t_cnvas *canvas,
	uint8_t *dst_data
)
{
	ft_memcpy(
		dst_data,
		canvas->buf,
		BMP_BYTE_PER_PIXEL * (size_t)(canvas->height) * (size_t)(canvas->width)
		)
	;
}

// ref: https://ruche-home.net/program/bmp/struct
__attribute__((nonnull))
size_t	canvas_to_bmp(
	const t_cnvas *canvas,
	uint8_t **dst
)
{
	size_t	len;

	if (canvas->buf == NULL
		|| canvas->height <= 0
		|| canvas->width <= 0
	)
		return (0);
	len = (size_t)(canvas->height) * (size_t)(canvas->width);
	if (!can_mul(BMP_BYTE_PER_PIXEL, len))
		return (0);
	len *= BMP_BYTE_PER_PIXEL;
	if (!can_add(BMP_FILEHEADER_LEN + BMP_HEADER_INFO_LEN, len))
		return (0);
	len += BMP_FILEHEADER_LEN + BMP_HEADER_INFO_LEN;
	*dst = malloc(len);
	if (*dst == NULL)
		return (0);
	_set_fileheader(*dst, len);
	_set_header_info(*dst + BMP_FILEHEADER_LEN, canvas->height, canvas->width);
	_set_pixels(canvas, *dst + BMP_FILEHEADER_LEN + BMP_HEADER_INFO_LEN);
	return (len);
}
