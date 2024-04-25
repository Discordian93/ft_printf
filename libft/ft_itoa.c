/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:41:47 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/05 16:41:48 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	num_len(int n);
static int	assign_is_negative(int *n);
static char	*handle_zero(void);
static char	*handle_other_ints(int n);
char		*ft_itoa(int n);

static int	num_len(int n)
{	
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	assign_is_negative(int *n)
{
	int	is_negative;

	is_negative = 0;
	if (*n < 0)
	{
		is_negative = 1;
		*n *= -1;
	}
	return (is_negative);
}

static char	*handle_zero(void)
{
	char	*representation;

	representation = malloc(sizeof(char) * 2);
	if (representation == NULL)
	{
		return (NULL);
	}
	representation[0] = '0';
	representation[1] = '\0';
	return (representation);
}

static char	*handle_other_ints(int n)
{
	int		str_len;
	char	*representation;
	int		char_position;
	int		is_negative;

	is_negative = assign_is_negative(&n);
	str_len = num_len(n);
	char_position = str_len - 1;
	representation = malloc(sizeof(char) * (str_len + is_negative + 1));
	if (representation == NULL)
	{
		return (NULL);
	}
	while (is_negative + char_position >= is_negative)
	{
		representation[is_negative + char_position] = (n % 10) + '0';
		n /= 10;
		char_position--;
	}
	representation[str_len + is_negative] = '\0';
	if (is_negative)
	{
		representation[0] = '-';
	}
	return (representation);
}

char	*ft_itoa(int n)
{	
	char	*representation;

	if (n == -2147483648)
	{
		representation = ft_itoa(n + 8);
		if (representation == NULL)
		{
			return (NULL);
		}
		representation[10] = '8';
		return (representation);
	}
	else if (n == 0)
	{
		return (handle_zero());
	}
	else
	{	
		return (handle_other_ints(n));
	}
}
/* #include <stdio.h>

int main()
{
    char *result;

    result = ft_itoa(0);
    printf("Test 1, input: 0, output: %s\n", result);
    free(result);

    result = ft_itoa(123);
    printf("Test 2, input: 123, output: %s\n", result);
    free(result);

    result = ft_itoa(-123);
    printf("Test 3, input: -123, output: %s\n", result);
    free(result);

    result = ft_itoa(2147483647);
    printf("Test 4, input: 2147483647 (INT_MAX), output: %s\n", result);
    free(result);

    result = ft_itoa(-2147483648);
    printf("Test 5, input: -2147483648 (INT_MIN), output: %s\n", result);
    free(result);

    return 0;
} */