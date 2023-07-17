/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:36:38 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 01:46:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - free
#include <stdlib.h>

#include <ft_string/ft_string.h>
#include <gnl/get_next_line.h>

#include <rt_loader.h>
#include <utils.h>

#include "_rt_loader.h"

#define TYPE_ID_AMB_LIGHT "A"
#define TYPE_ID_CAMERA "C"
#define TYPE_ID_LIGHT "L"
#define TYPE_ID_SPHERE "sp"
#define TYPE_ID_PLANE "pl"
#define TYPE_ID_CYLINDER "cy"

static t_lderr	_parse_input_obj(char *const arr[], t_scene *scene)
{
	t_lderr	err;
	t_objs	obj;

	obj = (t_objs){0};
	err = LOAD_ERR_SUCCESS;
	if (ft_strncmp(arr[0], TYPE_ID_SPHERE, sizeof(TYPE_ID_SPHERE)))
		obj.sphere = _load_sphere(arr, &err);
	else if (ft_strncmp(arr[0], TYPE_ID_PLANE, sizeof(TYPE_ID_PLANE)))
		obj.plane = _load_plane(arr, &err);
	else if (ft_strncmp(arr[0], TYPE_ID_CYLINDER, sizeof(TYPE_ID_CYLINDER)))
		obj.cylinder = _load_cylinder(arr, &err);
	else
		err = LOAD_ERR_UNKNOWN_TYPE_ID;
	if (err != LOAD_ERR_SUCCESS)
		return (err);
	if (!vect_push_back(&(scene->objs), &obj, NULL))
		return (perr_retint("parse_input_obj/push_back", LOAD_ERR_PRINTED));
	return (LOAD_ERR_SUCCESS);
}

static bool	_is_dup_def(bool *flag, t_lderr *err)
{
	if (*flag)
	{
		*err = LOAD_ERR_DUP_DEF;
		return (true);
	}
	else
	{
		*flag = true;
		return (false);
	}
}

static t_lderr	_parse_input(char *const arr[], t_scene *scene)
{
	t_lderr	err;

	if (ft_strncmp(arr[0], TYPE_ID_AMB_LIGHT, sizeof(TYPE_ID_AMB_LIGHT)))
	{
		if (!_is_dup_def(&(scene->is_amb_l_set), &err))
			scene->amb_light = _load_amb_light(arr, &err);
	}
	else if (ft_strncmp(arr[0], TYPE_ID_CAMERA, sizeof(TYPE_ID_CAMERA)))
	{
		if (!_is_dup_def(&(scene->is_amb_l_set), &err))
			scene->camera = _load_camera(arr, &err);
	}
	else if (ft_strncmp(arr[0], TYPE_ID_LIGHT, sizeof(TYPE_ID_LIGHT)))
	{
		if (!_is_dup_def(&(scene->is_amb_l_set), &err))
			scene->light = _load_light(arr, &err);
	}
	else
		err = _parse_input_obj(arr, scene);
	return (err);
}

__attribute__((nonnull))
t_lderr	load_rt_line(
	const char *line,
	t_scene *dst
)
{
	char	**arr;
	t_lderr	err;

	if (*line == '\0')
		return (LOAD_ERR_SUCCESS);
	arr = ft_split(line, ' ');
	if (arr == NULL)
		return (perr_retint("ft_split", LOAD_ERR_PRINTED));
	err = LOAD_ERR_SUCCESS;
	if (arr[0] != NULL)
		err = _parse_input(arr, dst);
	free2darr((void **)arr);
	return (err);
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
		tmp = get_next_line(&gnl);
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
