/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:30:26 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/14 15:43:29 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

void	check_set_player(t_sl *sl, char *line, int num, int index)
{
	if (line[index] == 'P')
	{
		sl->player_count++;
		if (sl->player_count > 1)
			sl->map[num][index] = '0';
		if (sl->player_count == 1)
		{
			sl->player_x = index;
			sl->player_y = num;
		}
	}
}

static int	index_line(t_sl *sl, char *line, int num)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		sl->map[num][index] = line[index];
		check_set_player(sl, line, num, index);
		if (line[index] == 'E')
			sl->exitset++;
		if (line[index] == 'C')
			sl->collectable_total++;
		if (line[index] != 'P' && line[index] != 'E' && line[index]
			!= 'C' && line[index] != '1' && line[index] != '0')
			error_mgs("Error: Wrong character in map");
		index++;
	}
	line[index] = '\0';
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
	while (num < sl->map_lines)
	{
		index_line(sl, line, num);
		if (ret != 0)
			free(line);
		ret = get_next_line(fd, &line);
		num++;
	}
	if (ret != 0)
		free(line);
	close(fd);
	return (0);
}
