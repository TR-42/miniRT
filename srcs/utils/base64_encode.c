/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:13:39 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/28 01:16:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <utils.h>

static size_t	_base64_calc_len(
	size_t len_bytes
)
{
	size_t	base64_len;

	base64_len = (len_bytes / 3) * 4;
	if ((len_bytes % 3) != 0)
		base64_len += 4;
	return (base64_len + 1);
}

static char	_to_base64_char(
	int d,
	bool ret_eq_char
)
{
	if (ret_eq_char)
		return ('=');
	d &= 0b00111111;
	if (d < 26)
		return ('A' + d);
	else if (d < 52)
		return ('a' + d - 26);
	else if (d < 62)
		return ('0' + d - 52);
	else if (d == 62)
		return ('+');
	else if (d == 63)
		return ('/');
	else
		return ('\0');
}

static void	_base64_encode_block(
	const unsigned char *d,
	size_t len,
	char *buf
)
{
	int	tmp;

	buf[0] = _to_base64_char(d[0] >> 2, false);
	tmp = ((d[0] & 0b11) << 4);
	if (1 < len)
		tmp += (d[1] >> 4);
	buf[1] = _to_base64_char(tmp, false);
	if (1 < len)
		tmp = (d[1] << 2);
	if (2 < len)
		tmp += (d[2] >> 6);
	buf[2] = _to_base64_char(tmp, len == 1);
	if (2 < len)
		tmp = (d[2]);
	buf[3] = _to_base64_char(tmp, len < 3);
}

__attribute__((nonnull))
char	*base64_encode(
	const unsigned char *d,
	size_t len
)
{
	size_t	i;
	size_t	loop_len;
	char	*buf;

	buf = (char *)malloc(_base64_calc_len(len));
	if (buf == NULL)
		return (NULL);
	i = 0;
	loop_len = len / 3;
	if ((len % 3) != 0)
		loop_len += 1;
	while (i < loop_len)
	{
		_base64_encode_block(d + (i * 3), len - (i * 3), buf + (i * 4));
		i++;
	}
	buf[i * 4] = '\0';
	return (buf);
}
