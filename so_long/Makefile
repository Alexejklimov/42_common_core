# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:46:09 by oklimov           #+#    #+#              #
#    Updated: 2025/02/17 12:27:10 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c src/map_create.c src/pathfinder.c gnl/get_next_line.c gnl/get_next_line_utils.c src/utils.c \
		src/mlx_utils.c src/moves.c

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./printf -I./libmlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 

OBJS = ${SRCS:.c=.o}

LIBMLX = minilibx-linux/libmlx.a

PRINTF = printf/libftprintf.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBMLX} ${PRINTF}
	${CC} ${OBJS} -o ${NAME} ${PRINTF} ${LIBMLX} ${MLX_FLAGS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}
	make -C printf clean

fclean: clean
	rm -f ${NAME}
	make -C printf clean

re: fclean all

${PRINTF}:
	make -C printf

$(LIBMLX):
	make -C minilibx-linux

.PHONY: all clean fclean re