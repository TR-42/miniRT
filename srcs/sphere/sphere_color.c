/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:50:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/13 19:42:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sphere.h>

__attribute__((nonnull))
t_rgb	sphere_color(
	const t_objs *obj,
	const t_ray *ray,
	double hit_at
)
{
	(void)ray;
	(void)hit_at;
	return (obj->sphere.color);
}
