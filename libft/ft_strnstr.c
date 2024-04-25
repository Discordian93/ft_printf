/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:20:19 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/23 18:20:21 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	else
	{
		while (*haystack != '\0' && len-- >= (unsigned int)ft_strlen(needle))
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			{
				return ((char *)haystack);
			}
			haystack++;
		}
		return (NULL);
	}
}
