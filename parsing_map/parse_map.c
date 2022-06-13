/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:25:04 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/13 13:16:57 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	map_malloc(t_sl *sl)
{
	int	i;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->map_lines);
	while (i < sl->map_lines)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->map_rows + 1));
		i++;
	}
	return (1);
}

int	set_w_h_2(t_sl *sl, char **line, int fd, int ret)
{
	sl->new_line_width = ft_strlen(*line);
	if (sl->new_line_width != sl->map_rows)
		error_mgs("Error: Map is not rectangular");
	if (ret != 0)
		free(*line);
	sl->map_lines++;
	ret = get_next_line(fd, line);
	return (ret);
}

int	get_width_and_height(t_sl *sl, char *map_file)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(map_file, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->map_rows = ft_strlen(line);
	while (ret == 1)
		ret = set_w_h_2(sl, &line, fd, ret);
	ret = set_w_h_2(sl, &line, fd, ret);
	if (ret != 0)
		free(line);
	close(fd);
	return (0);
}

int	parsing_map(t_vars *vars, char *map_file)
{
	map_exetention_check(map_file);
	get_width_and_height(vars->sl, map_file);
	map_malloc(vars->sl);
	index_map(vars->sl, map_file);
	check_map(vars->sl);
	return (0);
}
