/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:16:24 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:11:19 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;
	//mlx_image_t		*img_map;
	
	vars = param;
	if (keydata.action == MLX_PRESS)
	{
		printf("Key is %c\n", keydata.key);
		move_player(vars, keydata.key);
		move_hero_mlx(vars);
		edit_collectable(vars);
		if (vars->sl->exit_unlock == 1 && vars->sl->exit_edit_check == 0)
			edit_exit(vars);
		// img_map = set_map(vars->sl, vars->mlx);
		// set_walls(vars->sl, vars->mlx, img_map);
		// set_player(vars->sl, vars->mlx, img_map);
		// set_collectable(vars->sl, vars->mlx, img_map);
		// set_exit(vars, img_map);
	}
}

int	game_loop_mlx(t_sl *sl, int *game_exit)
{
	//mlx_image_t		*img_map;
	t_vars			vars;

	*game_exit = 1;
	vars.sl = sl;
	vars.mlx = mlx_init(64 * sl->map_width, 64 * sl->y, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	//set_textures(&vars);
	//img_map = set_map(sl, vars.mlx);
	init_mlx_map(&vars);
	// set_walls(sl, vars.mlx, img_map);
	// set_player(sl, vars.mlx, img_map);
	// set_collectable(sl, vars.mlx, img_map);
	// set_exit(&vars, img_map);
	mlx_key_hook(vars.mlx, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}
