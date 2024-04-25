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

char	*convert_hex_to_lowercase(char *hex_repr)
{
	char	*hex_og;

	hex_og = hex_repr;
	while (*hex_repr != '\0')
	{
		if (*hex_repr >= 'A' && *hex_repr <= 'F')
		{
			*hex_repr = *hex_repr - 'A' + 'a';
		}
		hex_repr++;
	}
	return (hex_og);
}