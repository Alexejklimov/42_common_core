# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 13:46:09 by oklimov           #+#    #+#              #
#    Updated: 2025/12/02 11:44:00 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++ 

CXX_FLAGS =  -Wall -Wextra -Werror -std=c++98

NAME = zombieHorde

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)


all: $(NAME)


$(NAME): $(OBJS) 
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 
	rm -rf $(OBJS_DIR)

re: fclean all