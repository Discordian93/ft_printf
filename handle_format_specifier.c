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
#include "libft.h"

int	handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_c(args));
	else if (specifier == 's')
		return (handle_s(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_d_or_i(args));
	else if (specifier == 'u')
		return (handle_u(args));
	else if (specifier == 'X' || specifier == 'x' || specifier == 'p')
		return (handle_hex_and_pointer(specifier, args));
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 0);
		return (1);
	}
	return (0);
}