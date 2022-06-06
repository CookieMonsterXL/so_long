/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:25:38 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/06 16:28:26 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"

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
