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
	sl->map = malloc(sizeof(char *) * sl->y);
	while (i < sl->y)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->x + 1));
		i++;
	}
	//sl->maptofree = 1;
	return (1);
}

int	get_width_and_height(t_sl *sl, char *map_file)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(map_file, O_RDONLY);
	ret = get_next_line(fd, &line);
	//printf("%s\n", line);
	sl->map_width = ft_strlen(line);
	while (line[0] == '1')
	{
		sl->x = ft_strlen(line);
		if (sl->x != sl->map_width)
			error_mgs("Map is not rectangular");
		sl->map_width = sl->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		//printf("%s\n", line);
		sl->y++;
	}
	if (sl->y == 0 || sl->x == 0)
		error_mgs("Map is not correct or not well formated");
	// sl->yscreen = sl->y * 64;
	free(line);
	// sl->xscreen = sl->x * 64;
	close(fd);
	return (0);
}

int	parsing(t_sl *sl, char *map_file)
{
	map_exetention_check(map_file);
	get_width_and_height(sl, map_file);
	map_malloc(sl);
	index_map(sl, map_file);
	check_map(sl);
	return (0);
}
