/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:24:13 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:28:52 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mymlx.h>
#include <X11/X.h>

__attribute__((nonnull))
static int	_on_exposed(t_mymlx *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

__attribute__((nonnull))
static int	_on_destroyed(t_mymlx *d)
{
	mlx_loop_end(d->mlx);
	return (0);
}

__attribute__((nonnull))
bool	mymlx_init(t_mymlx *mymlx, const t_scene *scene, int width, int height)
{
	*mymlx = (t_mymlx){0};
	mymlx->mlx = mlx_init();
	if (mymlx->mlx == NULL)
		return (false);
	mymlx->win = mlx_new_window(mymlx->mlx, width, height, "miniRT");
	if (mymlx->win == NULL)
		return (!mymlx_dispose(mymlx));
	mymlx->img = mlx_new_image(mymlx->mlx, width, height);
	if (mymlx->img == NULL)
		return (!mymlx_dispose(mymlx));
	mymlx->scene = scene;
	mlx_loop_hook(mymlx->mlx, on_loop, mymlx);
	mlx_expose_hook(mymlx->win, _on_exposed, mymlx);
	mlx_hook(mymlx->win, DestroyNotify, StructureNotifyMask,
		_on_destroyed, mymlx);
	return (true);
}
