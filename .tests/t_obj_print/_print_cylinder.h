/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_cylinder.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:31:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:41:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_CYLINDER_H
# define _PRINT_CYLINDER_H

# include <stdio.h>

# include <rt_types.h>

# include "../_print_rgb.h"
# include "../_print_vec3.h"
# include "_get_tobj_str.h"

static void	_print_cylinder(t_cylnd v)
{
	if (v.comm.type != T_OBJ_CYLINDER)
		printf("\t!!! ERR: Object type mismatch (expected CYLINDER but was %s)\n",
			_get_tobj_str(v.comm.type));
	_print_vec3("Center", v.center);
	_print_vec3("Axis", v.axis);
	printf("\tDiameter: %f\n", v.diameter);
	printf("\tHeight: %f\n", v.height);
	_print_rgb("Color", v.color);
}

#endif
