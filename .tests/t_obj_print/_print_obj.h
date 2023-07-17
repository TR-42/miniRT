/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_obj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:28:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:43:27 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_OBJ_H
# define _PRINT_OBJ_H

# include <stdio.h>

# include <rt_types.h>

# include "_get_tobj_str.h"

# include "_print_cylinder.h"
# include "_print_plane.h"
# include "_print_sphere.h"

static void	_print_obj(t_objs obj)
{
	printf("Object Type: %s\n", _get_tobj_str_of(obj));
	if (obj.comm.type == T_OBJ_CYLINDER)
		_print_cylinder(obj.cylinder);
	else if (obj.comm.type == T_OBJ_PLANE)
		_print_plane(obj.plane);
	else if (obj.comm.type == T_OBJ_SPHERE)
		_print_sphere(obj.sphere);
}

#endif
