/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brend_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:51:04 by kfujita           #+#    #+#             */
/*   Updated: 2023/08/20 15:16:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_rgb	brend_rgb(
	t_rgb a,
	t_rgb b,
	double ref_rate
)
{
	if (ref_rate <= 0)
		return ((t_rgb){0});
	return ((t_rgb){
		.r = ((int)a.r * b.r * ref_rate) / 255,
		.g = ((int)a.g * b.g * ref_rate) / 255,
		.b = ((int)a.b * b.b * ref_rate) / 255,
	});
}
