/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:56:57 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/22 00:00:19 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect3d.h>

t_vec3	vec3_reflect(
	t_vec3 input,
	t_vec3 normal
)
{
	double	in_norm_dot;

	in_norm_dot = vec3_dot(input, normal);
	return (
		vec3_sub(
			vec3_mul(normal, 2 * in_norm_dot),
			input
		)
	);
}
