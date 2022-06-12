/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:25:38 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 17:34:34 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	print_terminal(t_vars *vars, int *game_exit)
{
	int	i;

	i = 0;
	while (i < vars->sl->map_lines)
	{
		printf("%s\n", vars->sl->map[i]);
		i++;
	}
	*game_exit = 1;
	return (0);
}

int	game_loop_terinal(t_vars *vars, int *game_exit)
{
	int	c;

	print_terminal(vars, game_exit);
	while (1)
	{
		c = getchar();
		if (c == '\n')
			continue ;
		move_player(vars, c);
		print_terminal(vars, game_exit);
	}
}
