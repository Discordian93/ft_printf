#include "ft_printf.h"
#include "libft.h"

int	handle_c(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 0);
	return (1);
}