/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:42:36 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 19:56:20 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

#include <args.h>
#include <rt_types.h>
#include <utils.h>

#include "_args.h"

#define DEFAULT_HEIGHT 480
#define DEFAULT_WIDTH 640

#define DIR_SEPARATOR '/'

__attribute__((nonnull))
static bool	_str_end_with(
	const char *str,
	const char *end
)
{
	size_t		fname_len;
	size_t		end_len;
	const char	*fname;

	fname = ft_strrchr(str, DIR_SEPARATOR);
	if (fname == NULL || *fname == '\0' || fname[1] == '\0')
		fname = str;
	else
		fname++;
	fname_len = ft_strlen(fname);
	end_len = ft_strlen(end);
	if (fname_len <= end_len)
		return (false);
	return (ft_strncmp(fname + fname_len - end_len, end, end_len) == 0);
}

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
	else if (_is_arg_force_normalize(argv[*i]))
	{
		app->force_normalize = true;
		return (true);
	}
	else if (_str_end_with(argv[*i], RT_FILE_EXT))
		app->file_name = argv[*i];
	else
		return (errstr_retint(MSG_USAGE_TITLE, MSG_USAGE_CONTENT, false));
	return (true);
}

bool	parse_argv(
	int argc,
	const char *argv[],
	t_app *app
)
{
	int		i;

	if (argc < 2)
		return (errstr_retint(MSG_USAGE_TITLE, MSG_USAGE_CONTENT, false));
	i = 0;
	while (++i < argc)
	{
		if (!_parse_argv(app, &i, argc, argv))
			return (false);
	}
	if (app->file_name == NULL)
		return (errstr_retint(MSG_USAGE_TITLE, MSG_USAGE_CONTENT, false));
	if (app->height <= 0)
		app->height = DEFAULT_HEIGHT;
	if (app->width <= 0)
		app->width = DEFAULT_WIDTH;
	return (true);
}
