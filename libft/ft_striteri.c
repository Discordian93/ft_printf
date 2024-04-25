/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <esteizag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:54:36 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/15 10:54:40 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
// Additional code for testing
#include <stdio.h>
#include <ctype.h>

void to_upper(unsigned int i, char *c) {
	printf("%i\n", i);
    *c = toupper(*c);
}

int main() {
    char s[] = "Hello, World!";
    ft_striteri(s, to_upper);
    printf("%s\n", s);  // Should print "HELLO, WORLD!"

    char s2[] = "abc";
    ft_striteri(s2, to_upper);
    printf("%s\n", s2);  // Should print "ABC"

    return 0;
} */
