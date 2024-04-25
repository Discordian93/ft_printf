int	handle_hex_and_pointer(char specifier, va_list args)
{
	if (specifier == 'X')
		return (handle_X(args));
	else if (specifier == 'x')
		return (handle_x(args));
	else if (specifier == 'p')
		return (handle_p(args));
	return (0);
}