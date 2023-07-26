/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:23:14 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:27:23 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect3d.h>

// ref: http://www.math.s.chiba-u.ac.jp/~yasuda/Chiba/Lec/naiseki.pdf

t_vec3	vec3_cross(
	t_vec3 a,
	t_vec3 b
)
{
	return (
		vec3_(
			(a.y * b.z) - (b.y * a.z),
			(a.z * b.x) - (b.z * a.x),
			(a.x * b.y) - (b.x * a.y)
		)
	);
}
