/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:40:29 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/04 22:01:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plane.h>

t_objs	plane_init(
	t_vec3 point,
	t_vec3 orientation,
	t_rgb color
)
{
	t_objs	v;

	v = (t_objs){0};
	v.comm.type = T_OBJ_PLANE;
	plane_init_f(&(v.plane));
	v.plane.point = point;
	v.plane.orientation = orientation;
	v.plane.color = color;
	return (v);
}

void	plane_init_f(t_plane *v)
{
	v->comm.hit_func = plane_hit;
	v->comm.rgb_func = plane_color;
}
