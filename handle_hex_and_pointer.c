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
#include "libft/libft.h"

int	handle_hex_and_pointer(char specifier, va_list args)
{
	if (specifier == 'X')
		return (handle_x_uppercase(args));
	else if (specifier == 'x')
		return (handle_x(args));
	else if (specifier == 'p')
		return (handle_p(args));
	return (0);
}
