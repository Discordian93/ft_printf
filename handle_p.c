int	handle_p(va_list args)
{
	void	*p;
	char	*hex_repr;
	int		len;

	p = va_arg(args, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 0);
		return (ft_strlen("(nil)"));
	}
	else
	{
		ft_putstr_fd("0x", 0);
		hex_repr = num_to_hex((unsigned long long) p);
		hex_repr = convert_hex_to_lowercase(hex_repr);
		len = ft_strlen(hex_repr) + 2; // Add 2 for "0x"
		ft_putstr_fd(hex_repr, 0);
		free(hex_repr);
		return (len);
	}
}