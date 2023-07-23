/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_rgb.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:18:22 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:19:09 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINT_RGB_H
# define _PRINT_RGB_H

# include <stdio.h>
# include <rt_types.h>

static void	_print_rgb(const char *str, t_rgb rgb)
{
	printf("\t%s: (%3d,%3d,%3d) = (%02x,%02x,%02x)\n",
		str,
		rgb.r, rgb.g, rgb.b,
		rgb.r, rgb.g, rgb.b);
}

#endif
