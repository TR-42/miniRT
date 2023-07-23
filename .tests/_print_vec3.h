/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_vec3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:19:30 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:20:34 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_VEC3_H
# define _PRINT_VEC3_H

# include <stdio.h>

# include <vect3d.h>

# define FLOAT_FMT "%14.10f"

static void	_print_vec3(const char *str, t_vec3 v)
{
	printf("\t%s: (" FLOAT_FMT "," FLOAT_FMT "," FLOAT_FMT ")\n",
		str, v.x, v.y, v.z);
}

#endif
