/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:16:06 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/11 22:01:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <sphere.h>
#include <utils.h>

// ref: https://zenn.dev/mebiusbox/books/8d9c42883df9f6/viewer/b85221
//		#%F0%9F%93%8C-%E7%90%83%E3%81%AE%E8%BF%BD%E5%8A%A0
__attribute__((nonnull))
double	sphere_hit(
	const t_objs *obj,
	const t_ray *ray
)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	if (obj->comm.type != T_OBJ_SPHERE)
		return (false);
	oc = vec3_sub(ray->origin, obj->sphere.center);
	a = vec3_dot(ray->direction, ray->direction);
	b = 2 * vec3_dot(ray->direction, oc);
	c = vec3_dot(oc, oc) - pow2f(obj->sphere.diameter);
	d = pow2f(b) - (4 * a * c);
	if (d < 0)
		return (-1);
	return ((-b - sqrtf(d)) / (2 * a));
}
