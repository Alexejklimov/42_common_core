# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:46:09 by oklimov           #+#    #+#              #
#    Updated: 2025/07/15 16:54:05 by oklimov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++ 

CXX_FLAGS =  -Wall -Wextra -Werror -std=c++98


SRCS = MyAwesomePhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook


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