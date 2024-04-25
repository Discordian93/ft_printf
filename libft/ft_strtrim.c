/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <esteizag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:42:10 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/15 13:42:11 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*dst;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	dst = malloc(sizeof(char) * (end - start + 1));
	if (dst != NULL)
	{
		ft_strlcpy(dst, &s1[start], end - start + 1);
	}
	return (dst);
}

/* 
#include <stdio.h>

int main(void)
{
	char *s = "Hola";
	char *set = "oa";
	char *dst = ft_strtrim(s, set);
	printf("%s\n", dst);
	free(dst);
} */
