/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:40:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/09/17 00:41:43 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <plane.h>
#include <utils.h>

__attribute__((nonnull))
bool	plane_hit(
	const t_objs *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
)
{
	double	a;
	double	b;
	double	d;
	double	tmp;

	if (obj->comm.type != T_OBJ_PLANE)
		return (false);
	return (false);
}
