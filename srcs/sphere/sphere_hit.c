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

__attribute__((nonnull))
static double	_get_d(
	const t_objs *obj,
	const t_ray *ray,
	double *a,
	double *b
)
{
	t_vec3	oc;
	double	c;

	oc = vec3_sub(ray->origin, obj->sphere.center);
	*a = vec3_dot(ray->direction, ray->direction);
	*b = 2 * vec3_dot(ray->direction, oc);
	c = vec3_dot(oc, oc) - pow2f(obj->sphere.diameter / 2);
	return (pow2f(*b) - (4 * (*a) * c));
}

__attribute__((nonnull))
static bool	_set_hit_rec(
	const t_objs *obj,
	const t_ray *ray,
	double tmp,
	t_hit *hit_rec
)
{
	hit_rec->t = tmp;
	hit_rec->at = ray_at(ray, tmp);
	hit_rec->normal = vec3_div(vec3_sub(hit_rec->at, obj->sphere.center),
			obj->sphere.diameter / 2);
	return (true);
}

// ref: https://zenn.dev/mebiusbox/books/8d9c42883df9f6/viewer/b85221
//		#%F0%9F%93%8C-%E7%90%83%E3%81%AE%E8%BF%BD%E5%8A%A0
__attribute__((nonnull))
bool	sphere_hit(
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

	if (obj->comm.type != T_OBJ_SPHERE)
		return (false);
	d = _get_d(obj, ray, &a, &b);
	if (d <= 0)
		return (false);
	d = sqrtf(d);
	tmp = (-b - d) / (2 * a);
	if (t_range[0] < tmp && tmp < t_range[1])
		return (_set_hit_rec(obj, ray, tmp, hit_rec));
	return (false);
}
