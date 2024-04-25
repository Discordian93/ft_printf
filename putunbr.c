#include "ft_printf.h"
#include "libft.h"

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