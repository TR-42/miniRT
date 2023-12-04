/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:37:34 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:39:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <renderer.h>
#include <scene.h>

#if defined(DEBUG) || defined(ENABLE_PNG)

size_t	g_debug_x;
size_t	g_debug_y;

static void	_set_debug_x_y(
	size_t x,
	size_t y
)
{
	g_debug_x = x;
	g_debug_y = y;
}

#else

static void	_set_debug_x_y(
	size_t x,
	size_t y
)
{
	(void)x;
	(void)y;
}

#endif

__attribute__((nonnull))
void	render(
	t_cnvas *canvas,
	const t_scene *scene
)
{
	int		ix;
	int		iy;
	t_ray	ray;

	iy = 0;
	while (iy < canvas->height)
	{
		_set_debug_x_y(ix, iy);
		ix = 0;
		while (ix < canvas->width)
		{
			ray = cam_get_ray(&(scene->camera), canvas, ix, iy);
			canvas_set_color(canvas, ix, iy, ray_to_rgb(ray, scene));
			ix += 1;
		}
		iy += 1;
	}
}
