/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:39:29 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/11 21:41:15 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sphere.h>

t_objs	sphere_init(
	t_vec3 center,
	double diameter,
	t_rgb color
)
{
	t_objs	v;

	v = (t_objs){0};
	v.comm.type = T_OBJ_SPHERE;
	v.sphere.center = center;
	v.sphere.diameter = diameter;
	v.sphere.color = color;
	return (v);
}
