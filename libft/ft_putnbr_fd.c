/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <esteizag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:53:02 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/15 10:53:05 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_rec(int n, int fd)
{
	char	num_char;

	if (n < 0)
	{
		write(fd, "-", 1);
		putnbr_rec(-n, fd);
		return ;
	}
	if (n >= 10)
	{
		putnbr_rec(n / 10, fd);
	}
	num_char = (n % 10) + '0';
	write(fd, &num_char, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", ft_strlen("-2147483648"));
	}
	else
	{
		putnbr_rec(n, fd);
	}
}
/* #include "libft.h"
#include <fcntl.h>

int main(void)
{
    int fd1 = open("file1.txt", O_WRONLY | O_CREAT, 0644);
    int fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);
    int fd3 = open("file3.txt", O_WRONLY | O_CREAT, 0644);
	int fd4 = open("file4.txt", O_WRONLY | O_CREAT, 0644);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
    {
        // Handle error
        return 1;
    }

    ft_putnbr_fd(123, fd1);
    ft_putnbr_fd(-456, fd2);
    ft_putnbr_fd(-2147483648, fd3);
	ft_putnbr_fd(0, fd4);

    close(fd1);
    close(fd2);
    close(fd3);
	close(fd4);

    return 0;
} */
