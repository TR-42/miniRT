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

#endif
