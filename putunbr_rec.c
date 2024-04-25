#include "ft_printf.h"
#include "libft.h"

void	putunbr_rec(unsigned int n, int fd)
{
	char	num_char;

	if (n >= 10)
	{
		putunbr_rec(n / 10, fd);
	}
	num_char = (n % 10) + '0';
	write(fd, &num_char, 1);
}