SRCS = pipex.c utils.c argc_parcing.c

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./libft -I./libftprintf -g

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
	make -C libft clean
	make -C printf clean

re: fclean all

${LIBFT}:
	make -C libft

${PRINTF}:
	make -C printf

.PHONY: all clean fclean re