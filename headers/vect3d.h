/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/08 20:05:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT3D_H
# define VECT3D_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

// ref: https://hakuhin.jp/as/vec3d.html

t_vec3	vec3_(double x, double y, double z);

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_add3(t_vec3 a, t_vec3 b, t_vec3 c);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, double b);
t_vec3	vec3_div(t_vec3 a, double b);

double	vec3_len(t_vec3 a);

double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
t_vec3	vec3_normalize(t_vec3 a);

t_vec3	vec3_reflect(t_vec3 input, t_vec3 normal);

#endif
