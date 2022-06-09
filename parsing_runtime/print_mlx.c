/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:16:24 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/09 10:46:00 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

mlx_image_t		*set_collectable(t_sl *sl, mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("img/key_small.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	y = 0;
	while (y < sl->y)
	{
		x = 0;
		while (x < sl->map_width)
		{
			if (sl->map[y][x] == 'C')
				mlx_image_to_window(mlx, img_map, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (img_map);
}

mlx_image_t	*set_exit_closed(t_sl *sl, mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	uint32_t		xy[2];
	mlx_texture_t	*tile_texture;

	xy[0] = 64;
	xy[1] = 0;
	tile_texture = mlx_load_png("img/stone_gate.png");
	img_map = mlx_texture_area_to_image(mlx, tile_texture, xy, sl->texture_w_h);
	y = 0;
	while (y < sl->y)
	{
		x = 0;
		while (x < sl->map_width)
		{
			if (sl->map[y][x] == 'E')
				mlx_image_to_window(mlx, img_map, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (img_map);
}

mlx_image_t	*set_exit_open(t_sl *sl, mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	uint32_t		xy[2];
	mlx_texture_t	*tile_texture;

	xy[0] = 0;
	xy[1] = 0;
	tile_texture = mlx_load_png("img/stone_gate.png");
	img_map = mlx_texture_area_to_image(mlx, tile_texture, xy, sl->texture_w_h);
	y = 0;
	while (y < sl->y)
	{
		x = 0;
		while (x < sl->map_width)
		{
			if (sl->map[y][x] == 'E')
				mlx_image_to_window(mlx, img_map, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (img_map);
}

// mlx_image_t	*set_exit_visual_2(t_vars *vars, mlx_image_t *img_map, uint32_t *xy)
// {
// 	int				x;
// 	int				y;
// 	mlx_texture_t	*tile_texture;

// 	tile_texture = mlx_load_png("img/stone_gate.png");
// 	img_map = mlx_texture_area_to_image(vars->mlx, tile_texture, xy, vars->sl->texture_w_h);
// 	y = 0;
// 	while (y < vars->sl->y)
// 	{
// 		x = 0;
// 		while (x < vars->sl->map_width)
// 		{
// 			if (vars->sl->map[y][x] == 'E')
// 				mlx_image_to_window(vars->mlx, img_map, x * 64, y * 64);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (img_map);
// }

// mlx_image_t	*set_exit_visual(t_vars *vars, mlx_image_t *img_map)
// {
// 	uint32_t xy[2];
// 	int			x;
// 	int			y;
	
// 	x = 0;
// 	while (x < 4)
// 	{
// 		y = 0;
// 		while (y < 4)
// 		{
// 			xy[0] = x * 64;
// 			xy[1] = y * 64;
// 			set_exit_visual_2(vars, img_map, xy);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (img_map);
// }

mlx_image_t	*set_exit(t_vars *vars, mlx_image_t *img_map)
{
	if (vars->sl->exit_unlock == -1)
		set_exit_closed(vars->sl, vars->mlx, img_map);
	else if (vars->sl->exit_unlock == 1)// && vars->sl->exit_visual == 1)
		set_exit_open(vars->sl, vars->mlx, img_map);
	// else if (vars->sl->exit_unlock == 1 && vars->sl->exit_visual == -1)
	// {
	// 	vars->sl->exit_visual = 1;
	// 	set_exit_visual(vars, img_map);
	// }
	return (img_map);
}


mlx_image_t		*set_map(t_sl *sl, mlx_t *mlx)
{
	int				x;
	int				y;
	int				i;
	int				j;
	mlx_texture_t	*tile_texture;
	mlx_image_t		*img_map;

	tile_texture = mlx_load_png("img/ground64-1.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	j = 0;
	y = 0;
	while (j < sl->y)
	{
		i = 0;
		x = 0;
		while (i < sl->x)
		{
			i++;
			mlx_image_to_window(mlx, img_map, x, y);
			x = i * 64;
		}
		j++;
		y = j * 64;
	}
	return (img_map);
}

mlx_image_t		*set_walls(t_sl *sl, mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	int				i;
	int				j;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("img/tree64.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	j = 0;
	y = 0;
	while (j < sl->y)
	{
		i = 0;
		x = 0;
		while (i < sl->map_width)
		{
			if (sl->map[j][i] == '1')
				mlx_image_to_window(mlx, img_map, x, y);
			i++;
			x = i * 64;
		}
		j++;
		y = j * 64;
	}
	return (img_map);
}

mlx_image_t		*set_player(t_sl *sl, mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("img/hero64.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	y = 0;
	while (y < sl->y)
	{
		x = 0;
		while (x < sl->map_width)
		{
			if (sl->map[y][x] == 'P')
				mlx_image_to_window(mlx, img_map, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (img_map);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;
	mlx_image_t		*img_map;
	
	vars = param;
	if (keydata.action == MLX_PRESS)
	{
		printf("Key is %c\n", keydata.key);
		move_player(vars->sl, keydata.key);
		img_map = set_map(vars->sl, vars->mlx);
		set_walls(vars->sl, vars->mlx, img_map);
		set_player(vars->sl, vars->mlx, img_map);
		set_collectable(vars->sl, vars->mlx, img_map);
		set_exit(vars, img_map);
	}
}

int	game_loop_mlx(t_sl *sl, int *game_exit)
{
	mlx_image_t		*img_map;
	t_vars			vars;

	*game_exit = 1;
	vars.sl = sl;
	vars.mlx = mlx_init(64 * sl->map_width, 64 * sl->y, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	img_map = set_map(sl, vars.mlx);
	set_walls(sl, vars.mlx, img_map);
	set_player(sl, vars.mlx, img_map);
	set_collectable(sl, vars.mlx, img_map);
	set_exit(&vars, img_map);
	mlx_key_hook(vars.mlx, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}
