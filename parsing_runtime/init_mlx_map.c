/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:17:03 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 15:55:30 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

int	set_textures(t_vars *vars)
{
	vars->sl->ground_texture = mlx_load_png("img/ground64-1.png");

	// vars->sl->ground_img = mlx_texture_to_image(vars->mlx, vars->sl->ground_texture);
	// mlx_image_to_window(vars->mlx, vars->sl->ground_img, 0, 0);
	
	vars->sl->tree_texture = mlx_load_png("img/tree64.png");
	vars->sl->hero_texture = mlx_load_png("img/hero64.png");
	vars->sl->key_texture = mlx_load_png("img/key_small.png");
	vars->sl->exit_open_texture = mlx_load_png("img/gate_open.png");
	vars->sl->exit_close_texture = mlx_load_png("img/gate_close.png");
	return (0);
}

int	set_img(t_vars *vars)
{
	vars->sl->ground_img = mlx_texture_to_image(vars->mlx, vars->sl->ground_texture);
	//vars->sl->ground_img->instances[0].z = 1;
	vars->sl->tree_img = mlx_texture_to_image(vars->mlx, vars->sl->tree_texture);
	vars->sl->hero_img = mlx_texture_to_image(vars->mlx, vars->sl->hero_texture);
	vars->sl->key_img = mlx_texture_to_image(vars->mlx, vars->sl->key_texture);
	vars->sl->exit_open_img = mlx_texture_to_image(vars->mlx, vars->sl->exit_open_texture);
	vars->sl->exit_close_img = mlx_texture_to_image(vars->mlx, vars->sl->exit_close_texture);
	return (0);
}

int	init_map(t_vars *vars)
{
	set_ground(vars);
	set_trees(vars);
	set_hero(vars);
	set_collectable(vars);
	set_exit_closed(vars);
	return (0);
}

int	init_mlx_map(t_vars *vars)
{
	set_textures(vars);
	set_img(vars);
	init_map(vars);
	return (0);
}