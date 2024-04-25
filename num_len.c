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

int	num_len(int num)
{
	int	len;
	int	i;

	len = 0;
	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		len++;
		num = -num;
	}

	i = num;
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}