/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:52:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/09 14:46:09 by tbouma           ###   ########.fr       */
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

int	set_trees(t_vars *vars)
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				index;
	

	//index = mlx_image_to_window(vars->mlx, vars->sl->tree_img, 0, 0);
	j = 0;
	y = 0;
	while (j < vars->sl->y)
	{
		i = 0;
		x = 0;
		while (i < vars->sl->map_width)
		{
			if (vars->sl->map[j][i] == '1')
			{
				index = mlx_image_to_window(vars->mlx, vars->sl->tree_img, x, y);
				// vars->sl->tree_img->instances[index].x = x;
				// vars->sl->tree_img->instances[index].y = y;
				// vars->sl->tree_img->instances[index].z = 1;
			}
			i++;
			x = i * 64;
		}
		j++;
		y = j * 64;
	}
	return (index);
}


int	set_ground(t_vars *vars)
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				index;
//	mlx_texture_t	*tile_texture;
//	mlx_image_t		*img_map;

	//index = mlx_image_to_window(vars->mlx, vars->sl->ground_img, 0, 0);
	//vars->sl->ground_img->instances[index].x = 4;
	j = 0;
	y = 0;
	while (j < vars->sl->y)
	{
		i = 0;
		x = 0;
		while (i < vars->sl->x)
		{
			i++;
			// vars->sl->ground_img->instances[index].x = x;
			// vars->sl->ground_img->instances[index].y = y;
			// vars->sl->ground_img->instances[index].z = 0;
			index = mlx_image_to_window(vars->mlx, vars->sl->ground_img, x, y);
			//img_map->instances[index].
			x = i * 64;
		}
		j++;
		y = j * 64;
	}
	return (index);
}