/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbouma <tbouma@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 16:41:06 by tbouma        #+#    #+#                 */
/*   Updated: 2022/06/02 17:00:56 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # include <string.h>
// # include <stdlib.h>
// # include <stdbool.h>
// # include <limits.h>
# include <unistd.h>
# include <fcntl.h>

# define ADVANCE 13
# define BACK 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define RED_BUTTON 79
# define CLOSERED 17

typedef struct s_long
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
	int				move;
	int				playerset;
	int				exitset;
	int				collectibleset;

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
}					t_sl;


int	get_next_line(int fd, char **lines);

#endif