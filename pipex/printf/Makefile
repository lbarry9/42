
SRCS	=		ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnbr.c \
				ft_putptr.c \
				ft_puthex.c \
				ft_u_putnbr.c

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
CC		= cc -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -I. -c $< -o $@

$(NAME): $(OBJS) ft_printf.h
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
