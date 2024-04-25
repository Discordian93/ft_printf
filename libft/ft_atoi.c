/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:29:01 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/23 19:29:03 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*find_start(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	return (str);
}

static int	evaluate_sign(const char *str)
{
	int	sign;

	if (*str == '-')
	{
		sign = -1;
	}
	else
	{
		sign = 1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{	
	int	sign;
	int	sum;

	str = find_start(str);
	if (ft_strncmp(str, "-2147483648", ft_strlen("-2147483648")) == 0)
	{
		return (-2147483648);
	}
	sign = evaluate_sign(str);
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sign * sum);
}

/* #include <stdio.h>
#include <stdlib.h>

// Your ft_atoi function goes here

int main(void)
{
    char *test_cases[] = {
        "42",       // Expected: 42
        "-42",      // Expected: -42
        "   42",    // Expected: 42
        "\t\n\v\f\r42", // Expected: 42
		"+123",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        printf("Test case \"%s\":\n", test_cases[i]);
        printf("atoi: %d\n", atoi(test_cases[i]));
        printf("ft_atoi: %d\n\n", ft_atoi(test_cases[i]));
    }

    return 0;
} */
