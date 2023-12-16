/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _args.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:48:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 19:57:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGS_H
# define _ARGS_H

# include <rt_types.h>
# include <stdbool.h>

# define ARG_WIDTH "-w"
# define ARG_WIDTH_LONG "--width"
# define ARG_HEIGHT "-h"
# define ARG_HEIGHT_LONG "--height"

# define ARG_ALLOW_COMMENT "-c"
# define ARG_ALLOW_COMMENT_LONG "--allow-comment"

# define ARG_FORCE_NORMALIZE "-n"
# define ARG_FORCE_NORMALIZE_LONG "--force-normalize"

bool	_print_too_few_args(const char *msg);

int		_arg_atoi(
			const char *str
			)
		__attribute__((nonnull))
		;

bool	_is_arg_height(
			const char *str
			)
		__attribute__((nonnull))
		;

bool	_parse_arg_height(
			t_app *args,
			int *i,
			int argc,
			const char *argv[]
			)
		__attribute__((nonnull))
		;

bool	_is_arg_width(
			const char *str
			)
		__attribute__((nonnull))
		;

bool	_is_arg_allow_comment(
			const char *str
			)
		__attribute__((nonnull))
		;

bool	_is_arg_force_normalize(
			const char *str
			)
		__attribute__((nonnull))
		;

bool	_parse_arg_width(
			t_app *args,
			int *i,
			int argc,
			const char *argv[]
			)
		__attribute__((nonnull))
		;

#endif
