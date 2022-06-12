/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:52:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:38:08 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"
//#include "../includes/MLX42/include/MLX42/MLX42.h"


int	set_exit_open(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'E')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->exit_open_img, x * 64, y * 64);
				vars->sl->exit_open_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
	return (index);
}

int	set_exit_closed(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'E')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->exit_close_img, x * 64, y * 64);
				vars->sl->exit_close_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
	return (index);
}

int	set_collectable(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'C')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->key_img, x * 64, y * 64);
				vars->sl->key_img->instances[index].z = 3;
			}
			x++;
		}
		y++;
	}
	return (0);
}


int	set_hero(t_vars *vars)
{
	int				x;
	int				y;
	int				index;
	
	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == 'P')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->hero_img, x * 64, y * 64);
				vars->sl->hero_img->instances[index].z = 5;	
			}
			x++;
		}
		y++;
	}
	return (index);
}

int	set_trees(t_vars *vars)
{
	int				x;
	int				y;
	int				index;
	
	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->map_width)
		{
			if (vars->sl->map[y][x] == '1')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->tree_img, x * 64, y * 64);
				vars->sl->tree_img->instances[index].z = 2;
			}
			x++;
		}
		y++;
	}
	return (index);
}

int	set_ground(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

	y = 0;
	while (y < vars->sl->y)
	{
		x = 0;
		while (x < vars->sl->x)
		{
			index = mlx_image_to_window(vars->mlx, vars->sl->ground_img, x * 64, y * 64);
			vars->sl->ground_img->instances[index].z = 1;
			x++;
		}
		y++;
	}
	return (index);
}