/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:09:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/18 02:11:51 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cylinder.h>

t_objs	cylinder_init(
	t_vec3 center_axis[2],
	double diameter_height[2],
	t_rgb color
)
{
	t_objs	v;

	v = (t_objs){0};
	v.comm.type = T_OBJ_CYLINDER;
	cylinder_init_f(&(v.cylinder));
	v.cylinder.center = center_axis[0];
	v.cylinder.axis = center_axis[1];
	v.cylinder.diameter = diameter_height[0];
	v.cylinder.height = diameter_height[1];
	v.cylinder.color = color;
	return (v);
}

void	cylinder_init_f(t_cylnd *v)
{
	v->comm.hit_func = cylinder_hit;
}
