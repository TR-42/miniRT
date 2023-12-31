/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:01:39 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:08:37 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect3d.h>

t_vec3	vec3_add(
	t_vec3 a,
	t_vec3 b
)
{
	return (
		vec3_(
			a.x + b.x,
			a.y + b.y,
			a.z + b.z
		)
	);
}

t_vec3	vec3_add3(
	t_vec3 a,
	t_vec3 b,
	t_vec3 c
)
{
	return (
		vec3_(
			a.x + b.x + c.x,
			a.y + b.y + c.y,
			a.z + b.z + c.z
		)
	);
}
