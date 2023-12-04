/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:39:13 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/04 22:05:58 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plane.h>

__attribute__((nonnull))
t_rgb	plane_color(
	const t_objs *obj,
	const t_ray *ray,
	double hit_at
)
{
	(void)ray;
	(void)hit_at;
	return (obj->plane.color);
}
