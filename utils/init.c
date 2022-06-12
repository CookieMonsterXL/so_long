/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:59:36 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:06:31 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	init_struct(t_sl *sl)
{
	sl->keyboard[BACK] = 0;
	sl->keyboard[RED_BUTTON] = 0;
	sl->keyboard[ESC] = 0;
	sl->keyboard[LEFT] = 0;
	sl->keyboard[RIGHT] = 0;
	sl->keyboard[ADVANCE] = 0;
	sl->bpp = 0;
	sl->casein = 0;
	sl->casetotal = 0;
	sl->y = 0;
	sl->x = 0;
	sl->collectible = 0;
	sl->collectibletotal = 0;
	sl->collected = 0;
	sl->s_line = 0;
	sl->maptofree = -1;
	sl->move = 0;
	sl->player_count = 0;
	sl->collectibleset = 0;
	sl->exitset = 0;
	sl->exit_unlock = -1;
	
	sl->texture_w_h[0] = 64;
	sl->texture_w_h[1] = 64;
	sl->lastplayer_x = -1;
	sl->lastplayer_y = -1;
	sl->mlx_ptr = NULL;

	sl->exit_edit_check = 0;
	return (0);
}