/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:09:46 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/18 02:09:51 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cylinder.h>

__attribute__((nonnull))
t_rgb	cylinder_color(
	const t_objs *obj,
	const t_ray *ray,
	double hit_at
)
{
	(void)ray;
	(void)hit_at;
	return (obj->cylinder.color);
}
