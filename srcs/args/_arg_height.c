/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arg_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:00:03 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/08 23:53:49 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include "_args.h"

bool	_is_arg_height(
	const char *str
)
{
	return (
		ft_strncmp(str, ARG_HEIGHT, sizeof(ARG_HEIGHT)) == 0
		|| ft_strncmp(str, ARG_HEIGHT_LONG, sizeof(ARG_HEIGHT_LONG)) == 0
	);
}

bool	_parse_arg_height(
	t_app *args,
	int *i,
	int argc,
	const char *argv[]
)
{
	if (argc <= *i + 1)
		return (errstr_retint("Too few arguments", NULL, false));
	args->height = _arg_atoi(argv[*i + 1]);
	*i += 1;
	if (args->height < 0)
		return (errstr_retint("Invalid argument (height)", argv[*i], false));
	return (true);
}
