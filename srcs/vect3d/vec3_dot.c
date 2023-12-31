/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:22:00 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:22:37 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect3d.h>

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (
		(a.x * b.x)
		+ (a.y * b.y)
		+ (a.z * b.z)
	);
}
