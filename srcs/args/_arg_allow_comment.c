/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arg_allow_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:55:37 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/08 23:56:08 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include "_args.h"

bool	_is_arg_allow_comment(
	const char *str
)
{
	return (
		ft_strncmp(str, ARG_ALLOW_COMMENT, sizeof(ARG_ALLOW_COMMENT)) == 0
		|| ft_strncmp(
			str,
			ARG_ALLOW_COMMENT_LONG,
			sizeof(ARG_ALLOW_COMMENT_LONG)
		) == 0
	);
}
