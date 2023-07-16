/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:44:51 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 01:29:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stddef.h>

/**
 * @brief 二次元配列の長さを求める
 * 
 * @param arr2d 二次元配列へのポインタ
 * @return size_t 配列の長さ (NULLの場合は0が返る)
 */
size_t	arrlen2d(
			const void *const *arr2d
			);

/**
 * @brief 小数文字列をdoubleに変換する。指数標記には非対応。
 * 
 * @param str 文字列(先頭の空白は無視される)
 * @param endptr 無効となった場所のポインタ(NULLが渡された場合は、ポインタを記録しない)
 * @return double 解析結果
 */
double	ft_strtod(
			const char *str,
			char **endptr
			);

/**
 * @brief 指定の数字文字列をbyte型に変換する
 * 
 * @param str 文字列
 * @param dst 解析結果の値を記録する場所
 * @return bool 解析に成功したかどうか
 */
bool	try_str_to_byte(
			const char *str,
			unsigned char *dst
			)
		__attribute__((nonnull))
		;

/**
 * @brief 小数文字列をdoubleに変換する。指数標記には非対応。
 * 
 * @param str 文字列(先頭の空白は無視される)
 * @param endptr 無効となった場所のポインタ(NULLが渡された場合は、ポインタを記録しない)
 * @param dst 解析結果の値を書き込む場所
 * @return bool 解析に成功したかどうか (指定の文字列内に有効な数値のみが存在した場合にTRUE)
 */
bool	try_strtod(
			const char *str,
			char **endptr,
			double *dst
			);

/**
 * @brief 二次元配列のfreeを行う。ft_splitを行ったものなど。
 * 
 * @param arr2d freeをかける二次元配列
 * @return void* 常にNULLを返す
 */
void	*free2darr(
			void **arr2d
			);

/**
 * @brief 現在のerrnoを読み取り、それにあったエラー文を出力したうえでプログラムを終了する
 * 
 * @param str エラー文の前に出力する文字列
 */
void	perr_exit(
			const char *str
			)
		__attribute__((noreturn))
		;

/**
 * @brief 指定のerrnoにあったエラー文を出力したうえでプログラムを終了する
 * 
 * @param str エラー文の前に出力する文字列
 * @param _errno 出力したいエラーの番号
 */
void	strerr_exit(
			const char *str,
			int _errno
			)
		__attribute__((noreturn))
		;

/**
 * @brief 指定のエラー文を出力したうえでプログラムを終了する
 * 
 * @param str エラー文の前に出力する文字列
 * @param msg 出力したいエラー文
 */
void	errstr_exit(
			const char *str,
			const char *msg
			)
		__attribute__((noreturn))
		;

#endif
