/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/06/06 14:13:38 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1000
#define HEIGHT 1000
#include "includes/libft/libft.h"
#include "includes/so_long.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

mlx_image_t		*set_map(mlx_t *mlx, mlx_image_t *img_map)
{
	int				x;
	int				y;
	int				i;
	int				j;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("ground_tile.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	j = 0;
	y = 0;
	while (y < 900)
	{
		i = 0;
		x = 0;
		while (x < 900)
		{
			i++;
			mlx_image_to_window(mlx, img_map, x, y);
			x = i * 24;
		}
		j++;
		y = j * 24;
	}
	return (img_map);
}

mlx_image_t		*set_walls(mlx_t *mlx, mlx_image_t *img_map)
{
		int				x;
	int				y;
	int				i;
	int				j;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("tree.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	j = 0;
	y = 0;
	while (y < 900)
	{
		i = 0;
		x = 0;
		while (x < 900)
		{
			i++;
			if (x == 0 || y == 0 || x == 888 || y == 888)
				mlx_image_to_window(mlx, img_map, x, y);
			x = i * 24;
		}
		j++;
		y = j * 24;
	}
	return (img_map);
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img_map;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// tile_texture = mlx_load_png("ground_tile.png");
	// img_map =  mlx_texture_to_image(mlx, tile_texture);
	img_map = set_map(mlx, img_map);
	set_walls(mlx, img_map);
	// mlx_image_to_window(mlx, img_map, 0, 0);
	// mlx_image_to_window(mlx, img_map, 24, 24);
	//mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}