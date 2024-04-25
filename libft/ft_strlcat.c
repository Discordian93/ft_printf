/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:53:49 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/15 14:53:51 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (src[i] != '\0' && dstlen + i < size - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/* #include <stdio.h>

int main()
{
	char dst[50] = "Hello";
	const char *src = " World!";
	size_t size = sizeof(dst);

	printf("Before ft_strlcat: %s\n", dst);
	size_t ret = ft_strlcat(dst, src, size);
	printf("After ft_strlcat: %s\n", dst);
	printf("Returned value: %zu\n", ret);

	return 0;
}
 */