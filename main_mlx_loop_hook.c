/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx_loop_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:34:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/14 16:04:37 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"
//#include "includes/MLX42/include/MLX42/MLX42.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = param;
	if (keydata.action == MLX_PRESS)
	{
		if (vars->sl->player_won == 1)
		{
			if (keydata.key == MLX_KEY_ESCAPE)
				exit(1);
			return ;
		}
		move_player(vars, keydata.key);
		if (vars->sl->player_won == 1)
			player_won(vars);
		move_hero_mlx(vars);
		edit_collectable(vars);
		if (vars->sl->exit_unlock == 1 && vars->sl->exit_edit_check == 0)
			edit_exit(vars);
	}
}

int	game_loop_mlx(t_vars *vars)
{
	vars->mlx = mlx_init(64 * vars->sl->map_rows, 64
			* vars->sl->map_lines, "MLX42", true);
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	init_mlx_map(vars);
	mlx_key_hook(vars->mlx, key_hook, vars);
	mlx_loop(vars->mlx);
	mlx_terminate(vars->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_sl	sl;
	int		exit_status;

	vars.sl = &sl;
	init_struct(&vars);
	if (argc == 1)
		error_mgs("Error: No map");
	if (argc > 2)
		error_mgs("Error: Too many arguments");
	parsing_map(&vars, argv[1]);
	exit_status = game_loop_mlx(&vars);
	exit(exit_status);
	return (0);
}

	//system("leaks so_long");
	//game_loop_terminal(&sl, &game_exit);