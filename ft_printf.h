/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:47:00 by meltek            #+#    #+#             */
/*   Updated: 2024/04/25 18:47:02 by meltek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int				handle_c(va_list args);
int				handle_d_or_i(va_list args);
int				handle_format_specifier(char specifier, va_list args);
int				handle_hex_and_pointer(char specifier, va_list args);
int				handle_p(va_list args);
int				handle_s(va_list args);
int				handle_u(va_list args);
int				handle_x(va_list args);
int				handle_x_uppercase(va_list args);
char			i_to_hex(unsigned int c);
int				num_len(int num);
char			*num_to_hex(unsigned long long n);
void			ft_putunbr_fd(int n, int fd);
void			putunbr_rec(unsigned int n, int fd);
int				unum_len(unsigned long long num);
char			*convert_hex_to_lowercase(char *hex_repr);


#endif