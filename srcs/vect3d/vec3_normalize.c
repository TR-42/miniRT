/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:29:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:31:12 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vect3d.h>

t_vec3	vec3_normalize(
	t_vec3 a
)
{
	double	len;

	len = vec3_len(a);
	if (len != 0)
		len /= len;
	return (vec3_mul(a, len));
}
