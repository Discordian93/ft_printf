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

int	handle_p(va_list args)
{
	void	*p;
	char	*hex_repr;
	int		len;

	p = va_arg(args, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	else
	{
		ft_putstr_fd("0x", 1);
		hex_repr = num_to_hex((unsigned long long) p);
		hex_repr = convert_hex_to_lowercase(hex_repr);
		len = ft_strlen(hex_repr) + 2;
		ft_putstr_fd(hex_repr, 1);
		free(hex_repr);
		return (len);
	}
}