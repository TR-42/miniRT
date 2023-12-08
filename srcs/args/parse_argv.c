/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:42:36 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/09 00:02:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args.h>
#include <rt_types.h>
#include <utils.h>

#define DEFAULT_HEIGHT 480
#define DEFAULT_WIDTH 640

static bool	_parse_argv(
	t_app *app,
	int *i,
	int argc,
	const char *argv[]
)
{
	if (_is_arg_width(argv[*i]))
		return (_parse_arg_width(app, i, argc, argv));
	else if (_is_arg_height(argv[*i]))
		return (_parse_arg_height(app, i, argc, argv));
	else if (_is_arg_allow_comment(argv[*i]))
	{
		app->allow_comment = true;
		return (true);
	}
	else
		app->file_name = argv[*i];
	return (true);
}

bool	parse_argv(
	int argc,
	const char *argv[],
	t_app *app
)
{
	int		i;
	bool	result;

	if (argc < 2)
		return (errstr_retint("Too few arguments", NULL, false));
	i = 0;
	while (++i < argc)
	{
		if (!_parse_argv(app, &i, argc, argv))
			return (false);
	}
	if (app->height <= 0)
		app->height = DEFAULT_HEIGHT;
	if (app->width <= 0)
		app->width = DEFAULT_WIDTH;
	return (true);
}
