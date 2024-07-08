# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 19:14:15 by lbarry            #+#    #+#              #
#    Updated: 2024/07/05 22:34:56 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harlFilter
SRC		= main.cpp \
			Harl.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDE = Harl.hpp

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
