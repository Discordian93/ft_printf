int	handle_u(va_list args)
{
	unsigned int	unum;
	int				len;

	unum = va_arg(args, unsigned int);
	ft_putunbr_fd(unum, 0);
	len = num_len(unum);
	return (len);
}