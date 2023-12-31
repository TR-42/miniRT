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

#include <ft_mem/ft_mem.h>

#include <sphere.h>

t_objs	sphere_init(
	t_vec3 center,
	double diameter,
	t_rgb color
)
{
	t_objs	v;

	ft_bzero(&v, sizeof(t_objs));
	v.comm.type = T_OBJ_SPHERE;
	sphere_init_f(&(v.sphere));
	v.sphere.center = center;
	v.sphere.diameter = diameter;
	v.sphere.color = color;
	return (v);
}

void	sphere_init_f(t_spher *v)
{
	v->comm.hit_func = sphere_hit;
	v->comm.rgb_func = sphere_color;
}
