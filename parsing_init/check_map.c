/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:39:31 by tiemen            #+#    #+#             */
/*   Updated: 2022/06/05 13:07:57 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

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
	if (sl->player_count != 1)
		error_mgs("Error: Need 1 player");
	if (sl->exitset != 1)
		error_mgs("Error: Need 1 exit");
	if (sl->collectibletotal == 0)
		error_mgs("Error: Need at least 1 collectable");
	//checkthewall(sl);
	return (0);
}
