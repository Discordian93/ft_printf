#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

char	*convert_hex_to_lowercase(char *hex_repr)
{
	char	*hex_og;

	hex_og = hex_repr;
	while (*hex_repr != '\0')
	{
		if (*hex_repr >= 'A' && *hex_repr <= 'F')
		{
			*hex_repr = *hex_repr - 'A' + 'a';
		}
		hex_repr++;
	}
	return (hex_og);
}

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

char	i_to_hex(unsigned int c)
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
		return ('\0');
	}
}
int	num_len(int num)
{
	int	len;
	int	i;

	len = 0;
	if (num == 0)
		return (1);

	if (num == -2147483648)
		return (11);

	if (num < 0)
	{
		len++;
		num = -num;
	}

	i = num;
	while (i > 0)
	{
		len++;
		i /= 10;
	}

	return (len);
}

int	unum_len(unsigned long long num)
{
	int					len;
	unsigned long long	i;

	len = 0;
	if (num == 0)
		return (1);
	i = num;
	while (i > 0)
	{
		len++;
		i /= 16;
	}
	return (len);
}
char	*num_to_hex(unsigned long long n)
{
	unsigned int		current_d;
	int					cindex;
	int					num_len;
	char				*buffers;

	if (n == 0)
		return ("0");
	num_len = unum_len(n);
	buffers = malloc(num_len + 1);
	if (buffers == NULL)
		return (buffers);
	cindex = num_len;
	while (n > 0)
	{
		current_d = n % 16;
		buffers[cindex - 1] = i_to_hex(current_d);
		cindex--;
		n /= 16;
	}
	buffers[num_len] = '\0';
	return (buffers);
}

int handle_x(va_list args)
{
	char	*hex_repr;
	int		num;
	int		len;

	num = va_arg(args, int);
	hex_repr = num_to_hex(num);
	hex_repr = convert_hex_to_lowercase(hex_repr);
	len = ft_strlen(hex_repr);
	ft_putstr_fd(hex_repr, 0);
	free(hex_repr);
	return (len);
}

int handle_X(va_list args)
{
	char	*hex_repr;
	int		num;
	int		len;

	num = va_arg(args, int);
	hex_repr = num_to_hex(num);
	len = ft_strlen(hex_repr);
	ft_putstr_fd(hex_repr, 0);
	free(hex_repr);
	return (len);
}

int	handle_p(va_list args)
{
	void	*p;
	char	*hex_repr;
	int		len;

	p = va_arg(args, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 0);
		return (ft_strlen("(nil)"));
	}
	else
	{
		ft_putstr_fd("0x", 0);
		hex_repr = num_to_hex((unsigned long long) p);
		hex_repr = convert_hex_to_lowercase(hex_repr);
		len = ft_strlen(hex_repr) + 2; // Add 2 for "0x"
		ft_putstr_fd(hex_repr, 0);
		free(hex_repr);
		return (len);
	}
}

int	handle_hex_and_pointer(char specifier, va_list args)
{
	if (specifier == 'X')
		return (handle_X(args));
	else if (specifier == 'x')
		return (handle_x(args));
	else if (specifier == 'p')
		return (handle_p(args));
	return (0);
}

int	handle_c(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 0);
	return (1);
}

int	handle_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 0);
	len = ft_strlen(str);
	return (len);
}

int	handle_d_or_i(va_list args)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 0);
	len = num_len(num);
	return (len);
}

int	handle_u(va_list args)
{
	unsigned int	unum;
	int				len;

	unum = va_arg(args, unsigned int);
	ft_putunbr_fd(unum, 0);
	len = num_len(unum);
	return (len);
}

int	handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_c(args));
	else if (specifier == 's')
		return (handle_s(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_d_or_i(args));
	else if (specifier == 'u')
		return (handle_u(args));
	else if (specifier == 'X' || specifier == 'x' || specifier == 'p')
		return (handle_hex_and_pointer(specifier, args));
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 0);
		return (1);
	}
	return (0);
}



int ft_printf(char const *s, ...)
{
	va_list	args;
	int     total_len;

	total_len = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			total_len += handle_format_specifier(*s, args);
		}
		else
		{
			ft_putchar_fd(*s, 0);
			total_len++;
		}
		s++;
	}
	va_end(args);
	return (total_len);
}
int main(void)
{	

	int x = 1;
	printf("%x %p\n", 156, NULL);
	ft_printf("%x %p\n", 156, NULL);

}