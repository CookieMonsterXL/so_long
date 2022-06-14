/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:34:23 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/14 14:59:36 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	edit_exit(t_vars *vars)
{
	vars->sl->exit_edit_check = 1;
	mlx_delete_image(vars->mlx, vars->sl->e_c_img);
	set_exit_open(vars);
	return (0);
}

int	set_exit_open(t_vars *vars)
{
	int				x;
	int				y;
	int				i;

	y = 0;
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
		{
			if (vars->sl->map[y][x] == 'E')
			{
				x *= 64;
				y *= 64;
				i = mlx_image_to_window(vars->mlx, vars->sl->e_o_img, x, y);
				vars->sl->e_o_img->instances[i].z = 4;
				x /= 64;
				y /= 64;
			}
			x++;
		}
		y++;
	}
	return (i);
}

int	edit_collectable(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	index = 0;
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
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
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
		{
			if (vars->sl->map[y][x] == 'P')
			{
				vars->sl->her_img->instances->x = x * 64;
				vars->sl->her_img->instances->y = y * 64;
			}
			x++;
		}
		y++;
	}
	return (0);
}
