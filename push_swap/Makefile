# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:46:09 by oklimov           #+#    #+#              #
#    Updated: 2025/01/17 14:29:35 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algo_lis.c find_best_move.c main.c movement.c movements_utils.c \
       parsing.c run_best_move.c sort_algo.c utils.c utils_sec.c \
       utils_third.c

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./libft -I./printf

OBJS = ${SRCS:.c=.o}

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${PRINTF}
	${CC} ${OBJS} -o ${NAME} ${LIBFT} ${PRINTF}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f ${NAME}
	make -C libft fclean
	make -C printf fclean

re: fclean all

$(LIBFT):
	make -C libft

${PRINTF}:
	make -C printf

.PHONY: all clean fclean re