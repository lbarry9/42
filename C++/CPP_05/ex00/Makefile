# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 19:12:29 by lbarry            #+#    #+#              #
#    Updated: 2024/08/26 21:59:18 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat
SRC		= main.cpp \
			src/Bureaucrat.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= include/Bureaucrat.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
