/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:14:41 by esteizag          #+#    #+#             */
/*   Updated: 2023/09/23 21:14:42 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*block;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (num && SIZE_MAX / num < size)
	{
		return (NULL);
	}
	total_size = num * size;
	block = malloc(total_size);
	if (block != NULL)
	{
		ft_memset(block, 0, total_size);
	}
	return (block);
}
