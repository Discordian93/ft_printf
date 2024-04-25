/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:26:35 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/15 17:26:37 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	while (n--)
	{
		p1 = (unsigned char *) s1;
		p2 = (unsigned char *) s2;
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		s1++;
		s2++;
	}
	return (0);
}
