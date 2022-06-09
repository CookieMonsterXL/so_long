/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.key                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:58:37 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/08 13:56:51 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

static int	edit_map(t_sl *sl, int *move)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = move[1] + sl->player_x;
	new_pos_y = move[0] + sl->player_y;
	sl->map[new_pos_y][new_pos_x] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_y = new_pos_y;
	sl->player_x = new_pos_x;
	return (0);
}

int	check_collectable(t_sl *sl)
{
	sl->collected++;
	//printf("col_total = %d colected = %d\n", sl->collectibletotal, sl->collected);
	if (sl->collected == sl->collectibletotal)
		sl->exit_unlock = 1;
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
		check_collectable(sl);
		return (1);
	}
	else if (new_pos == '1')
		ft_putstr_fd("\n\tCan not move into wall\n\n", 1);
	else if ((new_pos == 'E' && sl->exit_unlock == -1))
		ft_putstr_fd("\n\tNeed more collectabels\n\n", 1);
	return (0);
}

static int	set_move(int key, int *move)
{
	//printf("key is+ %c\n", key);
	if (key == 'W' || key == 'w')
		move[0] = -1;
	else if (key == 'S' || key == 's')
		move[0] = 1;
	else if (key == 'A' || key == 'a')
		move[1] = -1;
	else if (key == 'D' || key == 'd')
		move[1] = 1;
	else
	{
		ft_putstr_fd("\n\tUse WASD keys to move\n\n", 1);
		return (0);
	}
	return (1);
}

int	*move_player(t_sl *sl, int key)
{
	sl->next_move[0] = 0;
	sl->next_move[1] = 0;
	if (!set_move(key, sl->next_move))
		return (0);
	if (!check_move(sl, sl->next_move))
		return (0);
	edit_map(sl, sl->next_move);
	return (0);
}
