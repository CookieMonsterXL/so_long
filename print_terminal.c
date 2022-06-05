/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:25:38 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/05 16:54:09 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"

static int	edit_map(t_sl *sl, int *move)
{
	int		new_pos_x;
	int		new_pos_y;

	// printf("player x = %d\n", sl->player_x);
	// printf("player y = %d\n", sl->player_y);
	new_pos_x = move[1] + sl->player_x;
	new_pos_y = move[0] + sl->player_y;
	// printf("new posx= %d\n", new_pos_x);
	// printf("new posy= %d\n", new_pos_y);
	sl->map[new_pos_y][new_pos_x] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_y = new_pos_y;
	sl->player_x = new_pos_x;
	return (0);
}

static int	check_move(t_sl *sl, int *move)
{
	int		new_pos_x;
	int		new_pos_y;
	char	new_pos;

	new_pos_x = move[1] + sl->player_x;
	new_pos_y = move[0] + sl->player_y;
	new_pos = sl->map[new_pos_y][new_pos_x];
	if (new_pos == '0')
		return (1);
	else if (new_pos == 'E' && sl->exit_unlock == 1)
		error_mgs("Player won!");
	else if (new_pos == 'C')
	{
		sl->exit_unlock = 1;
		return (1);
	}
	else if (new_pos == '1')
		ft_putstr_fd("\n\tCan not move into wall\n\n", 1);
	else if ((new_pos == 'E' && sl->exit_unlock == -1))
		ft_putstr_fd("\n\tNeed more collectabels\n\n", 1);
	return (0);
}

static int	set_move(int c, int *move)
{
	if (c == 'w')
		move[0] = -1;
	else if (c == 's')
		move[0] = 1;
	else if (c == 'a')
		move[1] = -1;
	else if (c == 'd')
		move[1] = 1;
	else
	{
		ft_putstr_fd("\n\tUse WASD keys to move\n\n", 1);
		return (0);
		
	}
	return (1);
}

static int	*move_player(t_sl *sl, int c)
{
	int	*move;

	move = malloc(sizeof(int) * 2);
	move[0] = 0;
	move[1] = 0;
	if (!set_move(c, move))
		return (0);
	//printf("print move = [%d][%d]\n", move[0], move[1]);
	if (!check_move(sl, move))
		return (0);
	edit_map(sl, move);
	return (0);
}

int	print_terminal(t_sl *sl, int *game_exit)
{
	int	i;

	i = 0;
	while (i < sl->y)
	{
		printf("%s\n", sl->map[i]);
		i++;
	}
	*game_exit = 1;
	return (0);
}

int	game_loop(t_sl *sl, int *game_exit)
{
	int	c;

	print_terminal(sl, game_exit);
	while (1)
	{
		c = getchar();
		if (c == '\n')
			continue ;
		//printf("char is= %c\n", c); 
		move_player(sl, c);
		print_terminal(sl, game_exit);
	}
}
