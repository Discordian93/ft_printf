/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:06:11 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/13 19:06:14 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *ptr, int x, size_t len)
{	
	unsigned char	*p;

	p = (unsigned char *) ptr;
	while (len > 0)
	{
		*p = x;
		len--;
		p++;
	}
	return (ptr);
}
