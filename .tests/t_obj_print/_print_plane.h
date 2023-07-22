/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_plane.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:31:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:39:08 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_PLANE_H
# define _PRINT_PLANE_H

# include <stdio.h>

# include <rt_types.h>

# include "../_print_rgb.h"
# include "../_print_vec3.h"
# include "_get_tobj_str.h"

static void	_print_plane(t_plane v)
{
	if (v.comm.type != T_OBJ_PLANE)
		printf("\t!!! ERR: Object type mismatch (expected PLANE but was %s)\n",
			_get_tobj_str(v.comm.type));
	_print_vec3("     Center", v.center);
	_print_vec3("Orientation", v.orientation);
	_print_rgb("      Color", v.color);
}

#endif
