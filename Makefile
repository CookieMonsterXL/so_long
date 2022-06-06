# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:40:14 by tbouma            #+#    #+#              #
#    Updated: 2022/06/06 16:10:24 by tbouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
OBJFILES := obj/main.o obj/gnl.o obj/init.o obj/utils.o obj/parsing/check_map.o \
obj/parsing/index_map.o obj/parsing/parse_map.o obj/print_terminal.o obj/print_mlx.o \
obj/move_player.o
OBJFILES_DEBUG := 
LIBFT := includes/libft/libft.a
LIBMLX := includes/MLX42/libmlx42.a
HEADERS := -I includes/libft/
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS := includes/MLX42/libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS_DEBUG := -fsanitize=address -g3
CC := gcc

all: $(LIBFT) $(NAME) $(LIBMLX)

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

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./includes/libft

re: fclean all

.PHONY: clean all fclean re