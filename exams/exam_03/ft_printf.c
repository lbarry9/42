#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putstr(const char *str, int *len)
{
	int i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*len)++;
	}
}

void	ft_putnbr(int n, int *len)
{
	char c;
	long long int nbr = n;

	if (n < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
		(*len)++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		(*len)++;
	}
}

void	ft_puthex(unsigned long long int nbr, int *len)
{
	char base[16] = "0123456789abcdef";

	if (nbr == 0)
	{
		ft_putstr("0", len);
		return ;
	}
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, len);
		ft_puthex(nbr % 16, len);
	}
	if (nbr < 16)
	{
		write(1, &base[nbr], 1);
		(*len)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i = 0;
	int		len = 0;

	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), &len);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (str[i] == 'x')
				ft_puthex((unsigned long long int)va_arg(args, unsigned int), &len);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}


int main()
{
    int a = 123456;
    printf("og func return: %d\n", printf(""));
    printf("my func return: %d\n", ft_printf(""));
    printf("og func return: %d\n", printf("%s, %d, %x fini!\n", "lynda", 4, a));
    printf("my func return: %d\n", ft_printf("%s, %d, %x fini!\n", "lynda", 4, a));
    return (0);
}
