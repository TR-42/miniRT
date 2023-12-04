/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:35:23 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/21 21:37:27 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "canvas.h"
# include "rt_types.h"

void	render(
			t_cnvas *canvas,
			const t_scene *scene
			)
		__attribute__((nonnull))
		;

#endif
