/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <esteizag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:00 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/15 13:48:01 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

static char	*allocate_memory(char const *s, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < len)
	{
		if (s_len == SIZE_MAX)
			return (NULL);
		return (malloc(sizeof(char) * (s_len + 1)));
	}
	else
	{
		if (len == SIZE_MAX)
			return (NULL);
		return (malloc(sizeof(char) * (len + 1)));
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (substr != NULL)
			*substr = '\0';
		return (substr);
	}
	while (start--)
		s++;
	substr = allocate_memory(s, len);
	if (substr != NULL)
	{
		if (s_len < len)
			ft_strlcpy(substr, s, s_len + 1);
		else
			ft_strlcpy(substr, s, len + 1);
	}
	return (substr);
}

/* #include <stdio.h>

int main()
{
    char *s = "Hello, World!";
    char *substr;

    // Test case 1: Normal case
    substr = ft_substr(s, 7, 5);
    printf("Test case 1: %s\n", substr);
    free(substr);

    // Test case 2: `start` is 0
    substr = ft_substr(s, 0, 5);
    printf("Test case 2: %s\n", substr);
    free(substr);

    // Test case 3: `len` is 0
    substr = ft_substr(s, 7, 0);
    printf("Test case 3: %s\n", substr);
    free(substr);

    // Test case 4: `start` is equal to the length of the string
    substr = ft_substr(s, ft_strlen(s), 5);
    printf("Test case 4: %s\n", substr);
    free(substr);

    // Test case 5: `start` is greater than the length of the string
    substr = ft_substr(s, ft_strlen(s) + 1, 5);
    printf("Test case 5: %s\n", substr);
    free(substr);

    return 0;
} */
