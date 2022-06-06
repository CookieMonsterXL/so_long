/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:34:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/06 14:21:22 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"

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
	// display(&sl);
	return (0);
}
