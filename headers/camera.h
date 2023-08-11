/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:13:54 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/10 20:47:12 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "canvas.h"
# include "ray.h"
# include "rt_types.h"

t_ray	cam_get_ray(
			const t_cam *cam,
			const t_cnvas *canvas,
			int x,
			int y
			)
		__attribute__((nonnull))
		;

#endif
