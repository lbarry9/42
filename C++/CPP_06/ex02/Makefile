# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 19:12:29 by lbarry            #+#    #+#              #
#    Updated: 2024/09/10 11:44:02 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= identify
SRC		= main.cpp \
			Base.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp
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
