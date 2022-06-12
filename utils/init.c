/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:59:36 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 18:44:22 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	init_struct(t_sl *sl)
{
	sl->map_lines = 0;
	sl->new_line_width = 0;
	sl->collectible = 0;
	sl->collectibletotal = 0;
	sl->collected = 0;

	sl->player_count = 0;
	sl->collectibleset = 0;
	sl->exitset = 0;
	sl->exit_unlock = -1;

	sl->lastplayer_x = -1;
	sl->lastplayer_y = -1;

	sl->exit_edit_check = 0;
	return (0);
}