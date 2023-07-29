/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inline_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:09:07 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/28 01:32:36 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include <ft_put/ft_put.h>

#include <print_inline_img.h>
#include <utils.h>

#define PRINT_HEADER_1 "\033]1337;File=inline=1;size="
#define PRINT_HEADER_2 ";width=60:"
#define PRINT_END "\a\n"

static char	*_get_size_t_str(size_t v, char *buf)
{
	if (10 <= v)
		buf = _get_size_t_str(v / 10, buf);
	*buf = (v % 10) + '0';
	return (buf + 1);
}

static void	_print_header(size_t len)
{
	char	buf[32];

	write(STDOUT_FILENO, PRINT_HEADER_1, sizeof(PRINT_HEADER_1) - 1);
	*_get_size_t_str(len, buf) = '\0';
	ft_putstr_fd(buf, STDOUT_FILENO);
	write(STDOUT_FILENO, PRINT_HEADER_2, sizeof(PRINT_HEADER_2) - 1);
}

bool	print_inline_img(
	unsigned char *d,
	size_t len
)
{
	char	*base64_buf;

	base64_buf = base64_encode(d, len);
	if (base64_buf == NULL)
		return (false);
	_print_header(len);
	ft_putstr_fd(base64_buf, STDOUT_FILENO);
	free(base64_buf);
	write(STDOUT_FILENO, PRINT_END, sizeof(PRINT_END) - 1);
	return (true);
}
