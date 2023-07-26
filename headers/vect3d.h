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
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, double b);

#endif
