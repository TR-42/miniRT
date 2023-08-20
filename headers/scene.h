/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:33:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/14 00:36:19 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rt_types.h"

bool	ray_hit_any(
			const t_ray *ray,
			const t_objs *objs,
			size_t objs_len,
			t_hit *hit_rec
			)
		__attribute__((nonnull))
		;

t_rgb	ray_to_rgb(
			t_ray ray,
			const t_objs *objs,
			size_t objs_len
			)
		__attribute__((nonnull))
		;

#endif
