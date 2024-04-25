#include "ft_printf.h"
#include "libft.h"

int	handle_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 0);
	len = ft_strlen(str);
	return (len);
}