#include <stdio.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:41:06 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/05 13:33:34 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # include <stdlib.h>
// # include <string.h>
// # include <stdbool.h>
// # include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define ADVANCE	13
# define BACK		1
# define RIGHT		2
# define LEFT		0
# define ESC		53
# define RED_BUTTON	79
# define CLOSERED	17

typedef struct s_sl
{
	char			**map;

	int				new_line_width;
	int				map_lines;
	int				map_rows;

	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectibletotal;
	int				collected;

	int				player_count;
	int				exitset;
	int				exit_unlock;
	int				exit_edit_check;
	int				collectibleset;

	int				next_move[2];

	mlx_texture_t	*ground_texture;
	mlx_texture_t	*tree_texture;
	mlx_texture_t	*hero_texture;
	mlx_texture_t	*key_texture;
	mlx_texture_t	*exit_open_texture;
	mlx_texture_t	*exit_close_texture;

	mlx_image_t		*ground_img;
	mlx_image_t		*tre_img;
	mlx_image_t		*her_img;
	mlx_image_t		*key_img;
	mlx_image_t		*e_o_img;
	mlx_image_t		*e_c_img;
}	t_sl;

typedef struct s_vars
{
	t_sl			*sl;
	mlx_t			*mlx;
}	t_vars;

int		get_next_line(int fd, char **lines);
int		init_struct(t_sl *sl);

//PARSING MAP
int		parsing(t_sl *sl, char *map_file);

//MAP CHECK
int		map_exetention_check(char *str);
int		check_map(t_sl *sl);

//INDEXING MAP
int		index_map(t_sl *sl, char *filename);

//UTILS
void	error_mgs(char *str);

//PRINT TERMINAL
int	print_terminal(t_vars *vars, int *game_exit);
int	game_loop_terinal(t_vars *vars, int *game_exit);

//PRINT MLX
int		game_loop_mlx(t_sl *sl, int *game_exit);

//MOVE PAYER
int		*move_player(t_vars *vars, int key);

//SET TEXTURE
int	init_mlx_map(t_vars *vars);

//SET IMG
int		set_ground(t_vars *vars);
int		set_trees(t_vars *vars);
int		set_hero(t_vars *vars);
int		set_collectable(t_vars *vars);
int		set_exit_closed(t_vars *vars);

int		move_hero_mlx(t_vars *vars);
int		edit_collectable(t_vars *vars);
int		edit_exit(t_vars *vars);
int	set_exit_open(t_vars *vars);
#endif