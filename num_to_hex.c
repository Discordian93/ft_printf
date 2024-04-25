#include "ft_printf.h"
#include "libft.h"

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