/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:41:06 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/14 16:32:16 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_sl
{
	char			**map;

	int				new_line_width;
	int				map_lines;
	int				map_rows;

	int				player_x;
	int				player_y;

	int				collectable_total;
	int				collected;

	int				player_count;
	int				exitset;
	int				exit_unlock;
	int				exit_edit_check;

	int				next_move[2];
	int				move_counter;
	int				player_won;

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

//UTILS
int		get_next_line(int fd, char **lines);
void	error_mgs(char *str);
int		init_struct(t_vars *vars);
void	free_map(t_vars *vars);
void	player_won(t_vars *vars);

//PARSING MAP
int		parsing_map(t_vars *vars, char *map_file);
int		index_map(t_sl *sl, char *filename);
int		map_exetention_check(char *str);
int		check_map(t_sl *sl);

//PRINT TERMINAL
// int		print_terminal(t_vars *vars);
// int		game_loop_terminal(t_vars *vars);

//PRINT MLX
int		game_loop_mlx(t_vars *vars);

//MOVE PAYER
int		*move_player(t_vars *vars, int key);
int		check_collectable(t_sl *sl);
int		remove_collectable_mlx(t_vars *vars);

//SET TEXTURE
int		init_mlx_map(t_vars *vars);

//SET IMG
int		set_ground(t_vars *vars);
int		set_trees(t_vars *vars);
int		set_hero(t_vars *vars);
int		set_collectable(t_vars *vars);
int		set_exit_closed(t_vars *vars);

int		move_hero_mlx(t_vars *vars);
int		edit_collectable(t_vars *vars);
int		edit_exit(t_vars *vars);
int		set_exit_open(t_vars *vars);
int		set_exit_closed(t_vars *vars);
#endif