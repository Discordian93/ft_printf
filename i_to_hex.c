#include "ft_printf.h"
#include "libft.h"

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