/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:14:14 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/27 00:16:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

double	pow2f(
	double value
)
{
	return (value * value);
}

double	pow3f(
	double value
)
{
	return (pow2f(value) * value);
}

double	pow4f(
	double value
)
{
	return (pow3f(value) * value);
}
