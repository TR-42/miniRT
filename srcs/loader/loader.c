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

#define TYPE_ID_AMB_LIGHT "A"
#define TYPE_ID_CAMERA "C"
#define TYPE_ID_LIGHT "L"
#define TYPE_ID_SPHERE "sp"
#define TYPE_ID_PLANE "pl"
#define TYPE_ID_CYLINDER "cy"

static bool	_parse_input_obj(char *const arr[], t_scene *scene)
{
	(void)scene;
	if (ft_strncmp(arr[0], TYPE_ID_SPHERE, sizeof(TYPE_ID_SPHERE)))
		;
	else if (ft_strncmp(arr[0], TYPE_ID_PLANE, sizeof(TYPE_ID_PLANE)))
		;
	else if (ft_strncmp(arr[0], TYPE_ID_CYLINDER, sizeof(TYPE_ID_CYLINDER)))
		;
	else
		return (false);
	return (true);
}

static void	_split_and_parse(char *str, t_scene *scene)
{
	char	**arr;

	arr = ft_split(str, ' ');
	free(str);
	if (arr == NULL)
		perr_exit("ft_split");
	if (arr[0] == NULL)
		;
	else if (ft_strncmp(arr[0], TYPE_ID_AMB_LIGHT, sizeof(TYPE_ID_AMB_LIGHT)))
		;
	else if (ft_strncmp(arr[0], TYPE_ID_CAMERA, sizeof(TYPE_ID_CAMERA)))
		;
	else if (ft_strncmp(arr[0], TYPE_ID_LIGHT, sizeof(TYPE_ID_LIGHT)))
		;
	else if (!_parse_input_obj(arr, scene))
		errstr_exit("parse input: Unknwon Type Identifier", arr[0]);
	free2darr((void **)arr);
}

/**
 * @brief RTファイルを読み込み、解析し、sceneに記録して返す
 * 
 * @param fd RTファイルのファイルディスクリプタ
 * @return t_scene 読み込み/解析結果 (エラー発生時はexit(1))
 */
t_scene	load_rt(int fd)
{
	t_scene		scene;
	t_gnl_state	gnl;
	char		*tmp;

	scene = (t_scene){0};
	gnl = gen_gnl_state(fd, 4096);
	if (gnl.buf == NULL)
		perr_exit("gnl_init");
	errno = 0;
	while (true)
	{
		tmp = get_next_line(&gnl);
		if (tmp == NULL)
			break ;
		_split_and_parse(tmp, &scene);
	}
	if (errno != 0)
		strerr_exit("gnl", errno);
	dispose_gnl_state(&gnl);
	return (scene);
}
