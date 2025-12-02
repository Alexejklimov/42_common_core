# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 13:46:02 by oklimov           #+#    #+#              #
#    Updated: 2025/11/28 15:51:51 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++ 

CXX_FLAGS =  -Wall -Wextra -Werror -std=c++98


SRCS = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = BraiiiiiiinnnzzzZ


all: $(NAME)


$(NAME): $(OBJS) 
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)


%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: 
	rm -f $(NAME) $(OBJS)

re: clean all
