/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:39:31 by tiemen            #+#    #+#             */
/*   Updated: 2022/06/14 15:46:34 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	check_walls(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_rows)
	{
		if (sl->map[0][i] != '1' || sl->map[sl->map_lines - 1][i] != '1')
			error_mgs("Error: sides of map are not wall");
		i++;
	}
	i = 0;
	while (i < sl->map_lines)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->map_rows - 1] != '1')
			error_mgs("Error: sides of map are not wall");
		i++;
	}
	return (0);
}

int	map_exetention_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			error_mgs("Error: Could not open file");
		else
			close(i);
		return (0);
	}
	error_mgs("Error: Files without .ber extension is not accepted");
	return (0);
}

int	check_map(t_sl *sl)
{
	if (sl->player_count < 1)
		error_mgs("Error: Need a player");
	if (sl->exitset < 1)
		error_mgs("Error: Need at least one exit");
	if (sl->collectable_total == 0)
		error_mgs("Error: Need at least one collectable");
	if (sl->map_lines == 0 || sl->new_line_width == 0)
		error_mgs("Map is not correct or not well formated");
	check_walls(sl);
	return (0);
}
