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

static char	*fill_buffers_with_zero(char *buffers)
{
	buffers[0] = '0';
	buffers[1] = '\0';
	return (buffers);
}

char	*num_to_hex(unsigned long long n)
{
	unsigned int		current_d;
	int					cindex;
	int					num_len;
	char				*buffers;

	if (n == 0)
	{
		buffers = malloc(sizeof(char) * 2);
		if (buffers == NULL)
			return (buffers);
		return (fill_buffers_with_zero(buffers));
	}
	num_len = unum_len(n);
	buffers = malloc(num_len + 1);
	if (buffers == NULL)
		return (buffers);
	cindex = num_len;
	while (n > 0)
	{
		current_d = n % 16;
		buffers[cindex-- - 1] = i_to_hex(current_d);
		n /= 16;
	}
	buffers[num_len] = '\0';
	return (buffers);
}
