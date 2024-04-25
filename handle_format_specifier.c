int	handle_format_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_c(args));
	else if (specifier == 's')
		return (handle_s(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_d_or_i(args));
	else if (specifier == 'u')
		return (handle_u(args));
	else if (specifier == 'X' || specifier == 'x' || specifier == 'p')
		return (handle_hex_and_pointer(specifier, args));
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 0);
		return (1);
	}
	return (0);
}