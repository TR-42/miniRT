/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:51:37 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:53:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - XK_*
#include <X11/keysym.h>

#include <mymlx.h>

__attribute__((nonnull))
int	on_key_pressed(
	int keycode,
	t_mymlx *mymlx
)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mymlx->mlx);
	return (0);
}
