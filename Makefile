# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:40:14 by tbouma            #+#    #+#              #
#    Updated: 2022/06/13 13:23:29 by tbouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
OBJFILES := obj/main_mlx_loop_hook.o obj/utils/gnl.o obj/utils/init.o obj/utils/utils.o obj/parsing_map/check_map.o \
obj/parsing_map/index_map.o obj/parsing_map/parse_map.o obj/parsing_runtime/move_player.o \
obj/parsing_runtime/edit_collectables.o obj/setup_mlx/init_mlx_map.o obj/mlx_runtime/set_map.o  \
obj/mlx_runtime/edit_map.o obj/utils/print_terminal.o 
OBJFILES_DEBUG := 
LIBFT := includes/libft/libft.a
LIBMLX := includes/MLX42/libmlx42.a
HEADERS := -I includes/libft/
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g3
MLXFLAGS := includes/MLX42/libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS_DEBUG := -fsanitize=address -g3
CC := gcc

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	make -C ./includes/libft

$(LIBMLX):
	make -C ./includes/MLX42

$(NAME): $(OBJFILES)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJFILES) $(LIBFT) $(LIBMLX) $(HEADERS) -o $(NAME)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)
	make clean -C ./includes/libft
	make clean -C ./includes/MLX42

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./includes/libft
	make fclean -C ./includes/MLX42

re: fclean all

.PHONY: clean all fclean re