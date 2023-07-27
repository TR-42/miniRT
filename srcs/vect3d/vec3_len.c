/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:12:22 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:23:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <utils.h>

#include <vect3d.h>

double	vec3_len(
	t_vec3 a
)
{
	return (
		sqrt(
			pow2f(a.x)
			+ pow2f(a.y)
			+ pow2f(a.z)
		)
	);
}
