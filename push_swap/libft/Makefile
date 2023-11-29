
SRCS	=		ft_isdigit.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_memset.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_substr.c \
				ft_split.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstlast.c

OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
CC		= cc -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c libft.h
	$(CC) -I. -c $< -o $@

$(NAME): $(OBJS) libft.h
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
