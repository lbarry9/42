# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 19:14:15 by lbarry            #+#    #+#              #
#    Updated: 2024/08/05 14:27:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= animal
SRC		= main.cpp \
			src/Animal.cpp \
			src/Dog.cpp \
			src/Cat.cpp \
			src/WrongCat.cpp \
			src/WrongAnimal.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= include/Animal.hpp \
			include/Dog.hpp \
			include/Cat.hpp \
			include/WrongAnimal \
			include/WrongCat
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
