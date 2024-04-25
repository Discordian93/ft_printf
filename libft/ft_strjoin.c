/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:57:35 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/24 17:57:37 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	joinlen;
	char	*joint;

	joinlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	joint = malloc(sizeof(char) * joinlen);
	if (joint != NULL)
	{
		ft_strlcpy(joint, s1, joinlen);
		ft_strlcat(joint, s2, joinlen);
	}
	return (joint);
}

/* 
#include <stdio.h>
int main(void)
{
	char *s1 = "Hola";
	char *s2 = " Mundo";
	char *dst;
	dst = ft_strjoin(s1, s1);
	printf("%s %s\n", dst, s2);
	free(dst);
} */
