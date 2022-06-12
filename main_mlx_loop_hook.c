/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx_loop_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:34:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/12 16:38:29 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"
//#include "includes/MLX42/include/MLX42/MLX42.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;
	
	vars = param;
	if (keydata.action == MLX_PRESS)
	{
		printf("Key is %c\n", keydata.key);
		move_player(vars, keydata.key);
		move_hero_mlx(vars);
		edit_collectable(vars);
		if (vars->sl->exit_unlock == 1 && vars->sl->exit_edit_check == 0)
			edit_exit(vars);
	}
}

int	game_loop_mlx(t_sl *sl, int *game_exit)
{
	t_vars			vars;

	*game_exit = 1;
	vars.sl = sl;
	vars.mlx = mlx_init(64 * sl->map_width, 64 * sl->y, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	init_mlx_map(&vars);
	mlx_key_hook(vars.mlx, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	int		game_exit;

	game_exit = 1;
	init_struct(&sl);
	if (argc == 1)
		error_mgs("Error: No map");
	if (argc > 2)
		error_mgs("Error: Too many arguments");
	parsing(&sl, argv[1]);
	game_loop_mlx(&sl, &game_exit);
	return (0);
}

	//game_loop_terinal(&sl, &game_exit);