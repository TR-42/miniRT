/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:54:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 00:41:10 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_LOADER_H
# define RT_LOADER_H

# include "rt_types.h"

typedef enum e_load_err
{
	LOAD_ERR_SUCCESS,
	LOAD_ERR_PRINTED,
	LOAD_ERR_DUP_DEF,
	LOAD_ERR_UNKNOWN_TYPE_ID,
	LOAD_ERR_NOT_A_NUMBER,
	LOAD_ERR_VAL_OUT_OF_RANGE,
	LOAD_ERR_INVAL_ARGS_COUNT,
	LOAD_ERR_TOO_FEW_PARAMS,
	LOAD_ERR_NO_CAMERA,
	LOAD_ERR_NRM_VEC_LEN_ZERO,
	LOAD_ERR_NRM_VEC_LEN_NOT_1,
}	t_lderr;

/**
 * @brief RTファイルを読み込み、解析し、sceneに記録する
 * 
 * @param fd RTファイルのファイルディスクリプタ
 * @param dst sceneを書き込む場所
 * @return t_lderr 読み込み/解析結果 (エラー情報)
 */
t_lderr	load_rt(
			int fd,
			bool allow_comment,
			bool force_normalize,
			t_scene *dst
			)
		__attribute__((nonnull))
		;

/**
 * @brief RTファイルの一行を解析し、sceneに記録する
 * 
 * @param line RTファイルの一行
 * @param allow_comment コメント行を許可するかどうか
 * @param force_normalize 
 * @param dst sceneを書き込む場所
 * @return t_lderr 読み込み/解析結果 (エラー情報)
 */
t_lderr	load_rt_line(
			const char *line,
			bool allow_comment,
			bool force_normalize,
			t_scene *dst
			)
		__attribute__((nonnull))
		;

void	print_load_err(t_lderr err);

#endif
