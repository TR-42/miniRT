/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arg_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:00:03 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/08 23:53:09 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include <utils.h>

#include "_args.h"

bool	_is_arg_width(
	const char *str
)
{
	return (
		ft_strncmp(str, ARG_WIDTH, sizeof(ARG_WIDTH)) == 0
		|| ft_strncmp(str, ARG_WIDTH_LONG, sizeof(ARG_WIDTH_LONG)) == 0
	);
}

bool	_parse_arg_width(
	t_app *args,
	int *i,
	int argc,
	const char *argv[]
)
{
	if (argc <= *i + 1)
		return (errstr_retint("Too few arguments", NULL, false));
	args->width = _arg_atoi(argv[*i + 1]);
	*i += 1;
	if (args->width < 0)
		return (errstr_retint("Invalid argument (width)", argv[*i], false));
	return (true);
}
