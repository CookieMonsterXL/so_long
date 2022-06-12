/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:52:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:10:07 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

	// set_ground(vars);
	// set_trees(vars);
	// set_hero(vars);
	// set_collectable(vars);
	// set_exit(vars);

int	edit_exit(t_vars *vars)
{
	vars->sl->exit_edit_check = 1;
	mlx_delete_image(vars->mlx, vars->sl->exit_close_img);
	set_exit_open(vars);
	return (0);
}

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

int	move_hero_mlx(t_vars *vars)
{
	int				x;
	int				y;
	//int				index;
	
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
	return (0);//(index);
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