# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 19:12:29 by lbarry            #+#    #+#              #
#    Updated: 2024/09/10 18:42:48 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert
SRC		= main.cpp \
			ScalarConverter.cpp \
			utils.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= ScalarConverter.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
