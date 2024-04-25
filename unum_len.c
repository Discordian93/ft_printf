#include "ft_printf.h"
#include "libft.h"

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