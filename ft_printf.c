#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

static void	putunbr_rec(unsigned int n, int fd)
{
	char	num_char;

	if (n >= 10)
	{
		putunbr_rec(n / 10, fd);
	}
	num_char = (n % 10) + '0';
	write(fd, &num_char, 1);
}

void	ft_putunbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", ft_strlen("-2147483648"));
	}
	else
	{
		putunbr_rec(n, fd);
	}
}

char i_to_hex(unsigned int c)
{
	if (c >= 0 && c <= 9)
	{
		return (c + '0');
	}
	if (c > 9)
	{
		return ('A' + c - 10);
	}
	else
	{
		return '\0';
	}
}
char *num_to_hex(unsigned int n)
{
	unsigned int current_d;
	int cindex;
	int  num_len;
	unsigned int og_value;
	char *buffers;

	if (n == 0)
	{
		return ("0");
	}
	num_len = 0;
	og_value = n;
	while (n > 0)
	{
		num_len++;
		n /= 16;
	}
	buffers = malloc(num_len + 1);
	if (buffers == NULL)
	{
		return (buffers);
	}
	n = og_value;
	cindex = num_len;
	while (n > 0)
	{
		current_d = n%16;
		buffers[cindex - 1] = i_to_hex(current_d);
		cindex--;
		n /= 16;
	}
	buffers[num_len] = '\0';
	return buffers;	
}

int	ft_printf(char const *s, ...)
{	va_list	args;
	char *hex_repr;
	char *hex_og;

	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
			{
				ft_putchar_fd(va_arg(args, char), 0);
			}
			if (*s == 's')
			{
				ft_putstr_fd(va_arg(args, char*), 0);
			}
			if (*s == 'd' || *s == 'i')
			{
				ft_putnbr_fd(va_arg(args, int), 0);
			}
			if (*s == 'u')
			{
				ft_putunbr_fd(va_arg(args, unsigned int), 0);
			}

			if (*s == 'X')
			{
				hex_repr = num_to_hex(va_arg(args, int));
				ft_putstr_fd(hex_repr, 0);
				free(hex_repr);
			}
			if (*s == 'x')
			{
				hex_repr = num_to_hex(va_arg(args, int));
				hex_og = hex_repr;
				while (*hex_repr != '\0')
				{
					if (*hex_repr >= 'A' && *hex_repr <= 'F')
					{
						*hex_repr = *hex_repr - 'A' + 'a';
					}
					hex_repr++;
				}
				hex_repr = hex_og;
				ft_putstr_fd(hex_repr, 0);
				free(hex_repr);
			}
			if (*s == 'p')
			{
				hex_repr = num_to_hex(va_arg(args, unsigned int));
				ft_putstr_fd(hex_repr, 0);
				free(hex_repr);
			}
			if (*s == '%')
			{
				ft_putchar_fd('%', 0);
			}


		}
	}


}


int main(void)
{
	printf("%s\n", num_to_hex(16));
}