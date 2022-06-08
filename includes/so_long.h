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
	int				xscreen;
	int				yscreen;
	int				x;
	int				y;
	int				map_width;
	int				collectibleparse;
	int				exitparse;
	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectibletotal;
	int				collected;
	int				move;
	int				player_count;
	int				exitset;
	int				exit_unlock;
	int				exit_visual;
	int				collectibleset;
	uint32_t		texture_w_h[2];

	char			*pxl;
	int				bpp;
	int				s_line;
	double			casetotal;
	double			casein;
	int				ed;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[70000];
	int				maptofree;

	int				bpp_text[10];
	int				sline_text[10];
	int				ed_text[10];
	char			*ptr_text[10];
	void			*text[10];
	int				widthtext[10];
	int				heighttext[10];
	int				actualtext;
	unsigned int	color;
	int				next_move[2];
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
int		print_terminal(t_sl *sl, int *game_exit);
int		game_loop(t_sl *sl, int *game_exit);

//PRINT MLX
int		game_loop_mlx(t_sl *sl, int *game_exit);

//MOVE PAYER
int		*move_player(t_sl *sl, int c);

#endif