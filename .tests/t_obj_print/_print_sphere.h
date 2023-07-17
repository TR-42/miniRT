/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_sphere.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:31:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:37:28 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_SPHERE_H
# define _PRINT_SPHERE_H

# include <stdio.h>

# include <rt_types.h>

# include "../_print_rgb.h"
# include "../_print_vec3.h"
# include "_get_tobj_str.h"

static void	_print_sphere(t_spher v)
{
	if (v.comm.type != T_OBJ_SPHERE)
		printf("\t!!! ERR: Object type mismatch (expected SPHERE but was %s)\n",
			_get_tobj_str(v.comm.type));
	_print_vec3("Center", v.center);
	printf("\tDiameter: %f\n", v.diameter);
	_print_rgb("Color", v.color);
}

#endif
