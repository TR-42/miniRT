/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:58:12 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/08 23:58:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "rt_types.h"

bool	parse_argv(
			int argc,
			const char *argv[],
			t_app *app
			)
		__attribute__((nonnull))
		;

#endif
