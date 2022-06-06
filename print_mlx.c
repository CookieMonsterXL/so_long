/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:16:24 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/06 16:53:10 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"
#include "includes/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256

// static int	edit_map(t_sl *sl, int *move)
// {
// 	int		new_pos_x;
// 	int		new_pos_y;

// 	new_pos_x = move[1] + sl->player_x;
// 	new_pos_y = move[0] + sl->player_y;
// 	sl->map[new_pos_y][new_pos_x] = 'P';
// 	sl->map[sl->player_y][sl->player_x] = '0';
// 	sl->player_y = new_pos_y;
// 	sl->player_x = new_pos_x;
// 	return (0);
// }

// static int	check_move(t_sl *sl, int *move)
// {
// 	int		new_pos_x;
// 	int		new_pos_y;
// 	char	new_pos;

// 	new_pos_x = move[1] + sl->player_x;
// 	new_pos_y = move[0] + sl->player_y;
// 	new_pos = sl->map[new_pos_y][new_pos_x];
// 	if (new_pos == '0')
// 		return (1);
// 	else if (new_pos == 'E' && sl->exit_unlock == 1)
// 		error_mgs("Player won!");
// 	else if (new_pos == 'C')
// 	{
// 		sl->exit_unlock = 1;
// 		return (1);
// 	}
// 	else if (new_pos == '1')
// 		ft_putstr_fd("\n\tCan not move into wall\n\n", 1);
// 	else if ((new_pos == 'E' && sl->exit_unlock == -1))
// 		ft_putstr_fd("\n\tNeed more collectabels\n\n", 1);
// 	return (0);
// }

// static int	set_move(int c, int *move)
// {
// 	if (c == 'w')
// 		move[0] = -1;
// 	else if (c == 's')
// 		move[0] = 1;
// 	else if (c == 'a')
// 		move[1] = -1;
// 	else if (c == 'd')
// 		move[1] = 1;
// 	else
// 	{
// 		ft_putstr_fd("\n\tUse WASD keys to move\n\n", 1);
// 		return (0);
		
// 	}
// 	return (1);
// }

// static int	*move_player(t_sl *sl, int c)
// {
// 	int	*move;

// 	move = malloc(sizeof(int) * 2);
// 	move[0] = 0;
// 	move[1] = 0;
// 	if (!set_move(c, move))
// 		return (0);
// 	if (!check_move(sl, move))
// 		return (0);
// 	edit_map(sl, move);
// 	return (0);
// }

// int	print_terminal(t_sl *sl, int *game_exit)
// {
// 	int	i;

// 	i = 0;
// 	while (i < sl->y)
// 	{
// 		printf("%s\n", sl->map[i]);
// 		i++;
// 	}
// 	*game_exit = 1;
// 	return (0);
// }

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
	int				i;
	int				j;
	mlx_texture_t	*tile_texture;

	tile_texture = mlx_load_png("img/hero64.png");
	img_map = mlx_texture_to_image(mlx, tile_texture);
	j = 0;
	y = 0;
	while (j < sl->y)
	{
		i = 0;
		x = 0;
		while (i < sl->map_width)
		{
			if (sl->map[j][i] == 'P')
				mlx_image_to_window(mlx, img_map, x, y);
			i++;
			x = i * 64;
		}
		j++;
		y = j * 64;
	}
	return (img_map);
}

void	hook(void *param)
{
	t_vars	*vars;
	char	c;

	vars = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_W))
		c = 'w';
	if (mlx_is_key_down(param, MLX_KEY_S))
		c = 's';
	if (mlx_is_key_down(param, MLX_KEY_A))
		c = 'a';
	if (mlx_is_key_down(param, MLX_KEY_D))
		c = 'd';
	
	move_player(vars->sl, c);
}


int	game_loop_mlx(t_sl *sl, int *game_exit)
{
	//mlx_t			*mlx;
	mlx_image_t		*img_map;
	t_vars			vars;


	*game_exit = 1;
	vars.mlx = mlx_init(64 * sl->map_width, 64 * sl->y, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	img_map = set_map(sl, vars.mlx);
	set_walls(sl, vars.mlx, img_map);
	set_player(sl, vars.mlx, img_map);
	vars.sl = sl;
	mlx_loop_hook(vars.mlx, hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);

	
	// int	c;

	// print_terminal(sl, game_exit);
	// while (1)
	// {
	// 	c = getchar();
	// 	if (c == '\n')
	// 		continue ;
	// 	//printf("char is= %c\n", c); 
	// 	move_player(sl, c);
	// 	print_terminal(sl, game_exit);
	// }
}