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

#include <ft_mem/ft_mem.h>
#include <ft_string/ft_string.h>

#include <rt_loader.h>
#include <utils.h>

#include "_rt_loader.h"

#define TID_AMB_LIGHT "A"
#define TID_CAMERA "C"
#define TID_LIGHT "L"
#define TID_SPHERE "sp"
#define TID_PLANE "pl"
#define TID_CYLINDER "cy"

static t_lderr	_parse_input_obj(
	char *const arr[],
	bool force_normalize,
	t_scene *scene
)
{
	t_lderr	err;
	t_objs	obj;

	ft_bzero(&obj, sizeof(t_objs));
	err = LOAD_ERR_SUCCESS;
	if (ft_strncmp(arr[0], TID_SPHERE, sizeof(TID_SPHERE)) == 0)
		obj.sphere = _load_sphere(arr, &err);
	else if (ft_strncmp(arr[0], TID_PLANE, sizeof(TID_PLANE)) == 0)
		obj.plane = _load_plane(arr, force_normalize, &err);
	else if (ft_strncmp(arr[0], TID_CYLINDER, sizeof(TID_CYLINDER)) == 0)
		obj.cylinder = _load_cylinder(arr, force_normalize, &err);
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

static t_lderr	_parse_input(
	char *const arr[],
	bool force_normalize,
	t_scene *scene
)
{
	t_lderr	err;

	if (ft_strncmp(arr[0], TID_AMB_LIGHT, sizeof(TID_AMB_LIGHT)) == 0)
	{
		if (!_is_dup_def(&(scene->is_amb_l_set), &err))
			scene->amb_light = _load_amb_light(arr, &err);
	}
	else if (ft_strncmp(arr[0], TID_CAMERA, sizeof(TID_CAMERA)) == 0)
	{
		if (!_is_dup_def(&(scene->is_camera_set), &err))
			scene->camera = _load_camera(arr, force_normalize, &err);
	}
	else if (ft_strncmp(arr[0], TID_LIGHT, sizeof(TID_LIGHT)) == 0)
	{
		if (!_is_dup_def(&(scene->is_light_set), &err))
			scene->light = _load_light(arr, &err);
	}
	else
		err = _parse_input_obj(arr, force_normalize, scene);
	return (err);
}

__attribute__((nonnull))
t_lderr	load_rt_line(
	const char *line,
	bool allow_comment,
	bool force_normalize,
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
	if (allow_comment)
		_ignore_comment(arr);
	if (arr[0] != NULL)
		err = _parse_input(arr, force_normalize, dst);
	free2darr((void **)arr);
	return (err);
}
