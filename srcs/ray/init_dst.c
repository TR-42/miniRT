/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:05:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/10 20:06:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>

t_ray	ray_init_dst(
	t_vec3 origin,
	t_vec3 dst
)
{
	return ((t_ray){
		.origin = origin,
		.direction = vec3_normalize(dst),
	});
}
