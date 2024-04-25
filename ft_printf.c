/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:47:00 by meltek            #+#    #+#             */
/*   Updated: 2024/04/25 18:47:02 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		total_len;

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
			ft_putchar_fd(*s, 1);
			total_len++;
		}
		s++;
	}
	va_end(args);
	return (total_len);
}
/* int main(void)
{	

	int x = 1;
	printf("%i\n", printf("%x %d %p\n hola\n", 156,-9, &x));
	printf("%i\n", ft_printf("%x %d %p\n hola\n", 156,-9, &x));

} */