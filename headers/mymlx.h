/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:17:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:24:56 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include <mlx.h>
# include <canvas.h>

# include "rt_types.h"

typedef struct s_mymlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_byte			*img_d;
	const t_scene	*scene;
	int				bpp;
	int				line_length;
	int				endian;
}	t_mymlx;

bool	mymlx_init(
			t_mymlx *mymlx,
			const t_scene *scene,
			int width,
			int height
			)
		__attribute__((nonnull))
		;

// always return true
bool	mymlx_dispose(
			t_mymlx *mymlx
			)
		__attribute__((nonnull))
		;

void	mymlx_set_image(
			t_mymlx *mymlx,
			const t_cnvas *canvas
			)
		__attribute__((nonnull))
		;

int		on_key_pressed(
			int keycode,
			t_mymlx *mymlx
			)
		__attribute__((nonnull))
		;

int		on_loop(
			t_mymlx *mymlx
			)
		__attribute__((nonnull))
		;

#endif
