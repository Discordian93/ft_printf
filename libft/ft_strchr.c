/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:57:53 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/15 15:57:55 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == uc)
	{
		return ((char *)s);
	}
	return (0);
}

/* #include <stdio.h>

char	*ft_strchr(const char *s, int c);

int main(void)
{
	char *str = "Hello, World!";
	int c1 = 'o';
	int c2 = ',';
	int c3 = '!';
	int c4 = 'z';
	int c5 = '\0';

	char *teste = "Hello, World!";
	char c6 = 'e';

	printf("Test 1: Searching for '%c' in \"%s\"\n", c1, str);
	char *result1 = ft_strchr(str, c1);
	if (result1 != NULL)
		printf("Result: \"%s\"\n\n", result1);
	else
		printf("Character not found.\n\n");

	printf("Test 2: Searching for '%c' in \"%s\"\n", c2, str);
	char *result2 = ft_strchr(str, c2);
	if (result2 != NULL)
		printf("Result: \"%s\"\n\n", result2);
	else
		printf("Character not found.\n\n");

	printf("Test 3: Searching for '%c' in \"%s\"\n", c3, str);
	char *result3 = ft_strchr(str, c3);
	if (result3 != NULL)
		printf("Result: \"%s\"\n\n", result3);
	else
		printf("Character not found.\n\n");

	printf("Test 4: Searching for '%c' in \"%s\"\n", c4, str);
	char *result4 = ft_strchr(str, c4);
	if (result4 != NULL)
		printf("Result: \"%s\"\n\n", result4);
	else
		printf("Character not found.\n\n");

	printf("Test 5: Searching for '\\0' in \"%s\"\n", str);
	char *result5 = ft_strchr(str, c5);
	if (result5 != NULL)
		printf("Result: \"%s\"\n\n", result5);
	else
		printf("Character not found.\n\n");
	char *result6 = ft_strchr(teste, c6);
	if (result6 != NULL)
		printf("Result: \"%s\"\n\n", result6);
	else
		printf("Character not found.\n\n");

	return (0);
}
 */