# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 16:28:43 by oklimov           #+#    #+#              #
#    Updated: 2025/07/16 15:58:42 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_striteri.c ft_bzero.c ft_calloc.c ft_isprint.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c \
			ft_atoi.c ft_strmapi.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \

BONUS_SRCS		= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJS_B		=  ${BONUS_SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

NAME		= libft.a

all:		${NAME}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJS_B}
			${AR} ${NAME} ${OBJS_B}
			ranlib ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
					rm -f ${OBJS} ${OBJS_B}

fclean:		clean
					rm -f ${NAME}

re:					fclean all

.PHONY:		all bonus clean fclean re
