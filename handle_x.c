int handle_x(va_list args)
{
	char	*hex_repr;
	int		num;
	int		len;

	num = va_arg(args, int);
	hex_repr = num_to_hex(num);
	hex_repr = convert_hex_to_lowercase(hex_repr);
	len = ft_strlen(hex_repr);
	ft_putstr_fd(hex_repr, 0);
	free(hex_repr);
	return (len);
}