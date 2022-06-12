#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:25:04 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/05 13:12:53 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	map_malloc(t_sl *sl)
{
	int	i;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->map_lines + 1);
	while (i < sl->map_lines)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->map_rows + 1));
		sl->map[i][sl->map_rows] = '\0';
		i++;
	}
	sl->map[sl->map_lines] = NULL;
	//sl->maptofree = 1;
	return (1);
}

int	set_w_h_2(t_sl *sl, char *line, int fd, int ret)
{
	sl->new_line_width = ft_strlen(line);
	if (sl->new_line_width != sl->map_rows)
		error_mgs("Map is not rectangular");
	if (ret != -1)
		free(line);
	sl->map_lines++;
	return (get_next_line(fd, &line));
}

int	get_width_and_height(t_sl *sl, char *map_file)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(map_file, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->map_rows = ft_strlen(line);
	while (ret == 1)//(line[0] == '1')
	{
		ret = set_w_h_2(sl, line, fd, ret);
	}
	ret = set_w_h_2(sl, line, fd, ret);

	// sl->new_line_width = ft_strlen(line);
	// if (sl->new_line_width != sl->map_rows)
	// 	error_mgs("Map is not rectangular");
	// sl->map_rows = sl->new_line_width;
	// if (ret != -1)
	// 	free(line);
	// ret = get_next_line(fd, &line);
	// sl->map_lines++;
	free(line);
	close(fd);
	return (0);
}

int	parsing(t_sl *sl, char *map_file)
{
	map_exetention_check(map_file);
	get_width_and_height(sl, map_file);

	printf("row = %d , lines = %d\n", sl->map_rows, sl->map_lines);

	map_malloc(sl);
	index_map(sl, map_file);
	check_map(sl);
	return (0);
}
