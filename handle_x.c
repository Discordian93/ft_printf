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

int handle_x(va_list args)
{
	char	*hex_repr;
	int		num;
	int		len;

	num = va_arg(args, int);
	hex_repr = num_to_hex(num);
	hex_repr = convert_hex_to_lowercase(hex_repr);
	len = ft_strlen(hex_repr);
	ft_putstr_fd(hex_repr, 0);
	free(hex_repr);
	return (len);
}