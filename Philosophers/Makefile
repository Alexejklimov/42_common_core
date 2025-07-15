
SRCS = src/philo.c src/utils.c src/die_action.c src/routine_action.c

NAME = philosophers

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread -g

OBJS = ${SRCS:.c=.o}

STEPS = 25

all: build

${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean build

.PHONY: all clean fclean re build

build:
	@make -s -q ${NAME} && echo "make: Nothing to be done for 'all'." || ( \
		i=1; \
		while [ $$i -le $(STEPS) ]; do \
			percent=$$((4 * $$i)); \
			bar_len=$$((percent)); \
			if   [ $$percent -le 10 ];  then color="\033[38;5;160m"; \
			elif [ $$percent -le 20 ];  then color="\033[38;5;196m"; \
			elif [ $$percent -le 30 ];  then color="\033[38;5;202m"; \
			elif [ $$percent -le 40 ];  then color="\033[38;5;226m"; \
			elif [ $$percent -le 50 ];  then color="\033[38;5;190m"; \
			elif [ $$percent -le 60 ];  then color="\033[38;5;154m"; \
			elif [ $$percent -le 70 ];  then color="\033[38;5;118m"; \
			elif [ $$percent -le 80 ];  then color="\033[38;5;82m"; \
			elif [ $$percent -le 90 ];  then color="\033[38;5;46m"; \
			else                          color="\033[38;5;40m"; fi; \
			bar="$$(printf '█%.0s' $$(seq 1 $$bar_len))"; \
			printf "\r\033[36mProgress: %3d%% \033[0m $${color}%-25s\033[0m" $$percent "$$bar "; \
			i=$$((i + 1)); \
			sleep 0.01; \
		done; \
		make -s ${NAME}; \
	)
