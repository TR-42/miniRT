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

#include <rt_loader.h>

/**
 * @brief RTファイルを読み込み、解析し、sceneに記録して返す
 * 
 * @param fd RTファイルのファイルディスクリプタ
 * @return t_scene 読み込み/解析結果 (エラー発生時はexit(1))
 */
t_scene	load_rt(int fd)
{
	t_scene	scene;

	(void)fd;
	scene = (t_scene){0};
	return (scene);
}
