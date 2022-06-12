/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:11:32 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 18:03:51 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

char	*recurs_read(int line_length, int *eof_check, int fd)
{
	char	buff[1];
	char	*lines;
	int		files;

	files = read(fd, buff, 1);
	if (files == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		lines = malloc(sizeof(char) * line_length + 1);
		if (!lines)
			return (0);
		lines[line_length] = 0;
		*eof_check = 1;
		if (buff[0] == 0)
			*eof_check = 0;
		return (lines);
	}
	else
	{
		lines = recurs_read(line_length + 1, eof_check, fd);
		lines[line_length] = buff[0];
	}
	return (lines);
}

int	get_next_line(int fd, char **lines)
{
	int	eof_check;

	eof_check = 1;
	*lines = recurs_read(0, &eof_check, fd);
	return (eof_check);
}
