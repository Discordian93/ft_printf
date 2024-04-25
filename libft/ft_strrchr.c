/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:59:07 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/15 15:59:10 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*last_occurrence;

	uc = (unsigned char)c;
	last_occurrence = NULL;
	while (*s)
	{
		if (*s == uc)
		{
			last_occurrence = (char *)s;
		}
		s++;
	}
	if (uc == '\0')
	{
		last_occurrence = (char *)s;
	}
	return (last_occurrence);
}
