/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inline_img.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:37:40 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/28 01:45:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

extern "C"
{
	#include <print_inline_img.h>
}

#define WRITE_FD(fd, str) (write(fd, str, sizeof(str) - 1))
#define WRITE(str) WRITE_FD(STDOUT_FILENO, str)

int main(
	int argc,
	const char *argv[]
)
{
	int			fd;
	struct stat	st;

	if (argc != 2)
	{
		WRITE_FD(STDERR_FILENO, "t_inline_img {FILE_PATH}\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	if (fstat(fd, &st) != 0)
	{
		perror("fstat");
		close(fd);
		return (1);
	}

	unsigned char *fileData = new unsigned char[st.st_size];
	read(fd, fileData, st.st_size);
	close(fd);

	bool success = print_inline_img(fileData, st.st_size);

	delete[] fileData;
	return (!success);
}
