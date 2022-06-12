/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:34:23 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:40:41 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	edit_exit(t_vars *vars)
{
	vars->sl->exit_edit_check = 1;
	mlx_delete_image(vars->mlx, vars->sl->exit_close_img);
	set_exit_open(vars);
	return (0);
}

int	edit_collectable(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	index = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'C')
			{
				vars->sl->key_img->instances[index].x = x * 64;
				vars->sl->key_img->instances[index].y = y * 64;
				index++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	move_hero_mlx(t_vars *vars)
{
	int				x;
	int				y;

	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'P')
			{
				vars->sl->hero_img->instances->x = x * 64;
				vars->sl->hero_img->instances->y = y * 64;
			}
			x++;
		}
		y++;
	}
	return (0);
}
