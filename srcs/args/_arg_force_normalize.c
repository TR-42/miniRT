/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arg_force_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:36:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 19:57:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include "_args.h"

bool	_is_arg_force_normalize(
	const char *str
)
{
	return (
		ft_strncmp(str, ARG_FORCE_NORMALIZE, sizeof(ARG_FORCE_NORMALIZE)) == 0
		|| ft_strncmp(
			str,
			ARG_FORCE_NORMALIZE_LONG,
			sizeof(ARG_FORCE_NORMALIZE_LONG)
		) == 0
	);
}
