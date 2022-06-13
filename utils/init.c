/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:59:36 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/13 13:29:01 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	init_struct(t_vars *vars)
{
	vars->sl->map_lines = 0;
	vars->sl->new_line_width = 0;
	vars->sl->collectable_total = 0;
	vars->sl->collected = 0;
	vars->sl->player_count = 0;
	vars->sl->exitset = 0;
	vars->sl->exit_unlock = -1;
	vars->sl->exit_edit_check = 0;
	return (0);
}
