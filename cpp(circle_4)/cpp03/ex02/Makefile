# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 13:46:09 by oklimov           #+#    #+#              #
#    Updated: 2025/12/11 08:49:18 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++ 

CXX_FLAGS =  -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

SRCS = src/main.cpp src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp
OBJS_DIR = obj
OBJS = $(SRCS:src/%.cpp=$(OBJS_DIR)/%.o)


all: $(NAME)


$(NAME): $(OBJS) 
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJS_DIR)/src
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 
	rm -rf $(OBJS_DIR)

re: fclean all