/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:25:38 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/09 10:46:16 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

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

int	game_loop_terinal(t_sl *sl, int *game_exit)
{
	int	c;

	print_terminal(sl, game_exit);
	while (1)
	{
		c = getchar();
		if (c == '\n')
			continue ;
		move_player(sl, c);
		print_terminal(sl, game_exit);
	}
}
