/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_deg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:23:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 19:25:23 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <vect3d.h>

double	vec3_deg(t_vec3 a, t_vec3 b)
{
	double	deg;
	double	rad;

	deg = vec3_dot(a, b) / (vec3_len(a) * vec3_len(b));
	rad = acos(deg);
	return (rad * 180 / M_PI);
}
