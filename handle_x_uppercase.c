#include "ft_printf.h"
#include "libft.h"

int handle_x_uppercase(va_list args)
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