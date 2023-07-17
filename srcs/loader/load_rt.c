/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:15:37 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/17 23:17:10 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - free
#include <stdlib.h>

// - errno
#include <errno.h>

#include <ft_string/ft_string.h>
#include <gnl/get_next_line.h>

#include <rt_loader.h>
#include <utils.h>

static	char	*_remove_lf(char *str)
{
	size_t	len;

	if (str == NULL || *str == '\0')
		return (str);
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

// 何かに失敗したら、その時点で解析を終了する。
// 今までの解析結果 (malloc済みのobjsなど) はfreeされないので注意
__attribute__((nonnull))
t_lderr	load_rt(
	int fd,
	t_scene *dst
)
{
	t_lderr		err;
	t_gnl_state	gnl;
	char		*tmp;

	*dst = (t_scene){0};
	err = LOAD_ERR_SUCCESS;
	gnl = gen_gnl_state(fd, 4096);
	if (gnl.buf == NULL)
		return (perr_retint("gnl_init", LOAD_ERR_PRINTED));
	dst->objs = vect_init(128, sizeof(t_objs));
	if (dst->objs.p == NULL)
		err = perr_retint("vect_init", LOAD_ERR_PRINTED);
	errno = 0;
	while (err == LOAD_ERR_SUCCESS)
	{
		tmp = _remove_lf(get_next_line(&gnl));
		if (tmp == NULL)
			break ;
		err = load_rt_line(tmp, dst);
		free(tmp);
	}
	if (errno != 0)
		err = perr_retint("gnl", LOAD_ERR_PRINTED);
	dispose_gnl_state(&gnl);
	return (err);
}
