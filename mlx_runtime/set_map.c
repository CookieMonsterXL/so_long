/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:52:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/14 14:59:24 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	set_exit_closed(t_vars *vars)
{
	int				x;
	int				y;
	int				index;

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
				index = mlx_image_to_window(vars->mlx, vars->sl->e_c_img, x, y);
				vars->sl->e_c_img->instances[index].z = 4;
				x /= 64;
				y /= 64;
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
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
		{
			if (vars->sl->map[y][x] == 'C')
			{
				x *= 64;
				y *= 64;
				index = mlx_image_to_window(vars->mlx, vars->sl->key_img, x, y);
				vars->sl->key_img->instances[index].z = 3;
				x /= 64;
				y /= 64;
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
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
		{
			if (vars->sl->map[y][x] == 'P')
			{
				x *= 64;
				y *= 64;
				index = mlx_image_to_window(vars->mlx, vars->sl->her_img, x, y);
				vars->sl->her_img->instances[index].z = 5;
				x /= 64;
				y /= 64;
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
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->map_rows)
		{
			if (vars->sl->map[y][x] == '1')
			{
				x *= 64;
				y *= 64;
				index = mlx_image_to_window(vars->mlx, vars->sl->tre_img, x, y);
				vars->sl->tre_img->instances[index].z = 2;
				x /= 64;
				y /= 64;
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
	while (y < vars->sl->map_lines)
	{
		x = 0;
		while (x < vars->sl->new_line_width)
		{
			x *= 64;
			y *= 64;
			index = mlx_image_to_window(vars->mlx, vars->sl->ground_img, x, y);
			vars->sl->ground_img->instances[index].z = 1;
			x /= 64;
			y /= 64;
			x++;
		}
		y++;
	}
	return (index);
}
