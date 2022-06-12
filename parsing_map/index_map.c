/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:30:26 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 17:54:25 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

static int	index_line(t_sl *sl, char *line, int num)
{
	int	index;

	index = 0;
	while (line[index] != '\0')//(line[index])
	{
		//sl->casetotal++;
		sl->map[num][index] = line[index];
		if (line[index] == 'P')
		{
			sl->player_count++;
			sl->player_x = index;
			sl->player_y = num;
		}
		if (line[index] == 'E')
			sl->exitset++;
		if (line[index] == 'C')
			sl->collectibletotal++;
		if (line[index] != 'P' && line[index] != 'E' && line[index]
			!= 'C' && line[index] != '1' && line[index] != '0')
			error_mgs("Error: Wrong character in map");
		index++;
	}
	return (0);
}

int	index_map(t_sl *sl, char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	int		num;

	num = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (num < sl->map_lines)//(line[0] == '1')
	{
		index_line(sl, line, num);
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		num++;
	}
	free(line);
	close(fd);
	return (0);
}