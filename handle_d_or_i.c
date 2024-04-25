int	handle_d_or_i(va_list args)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 0);
	len = num_len(num);
	return (len);
}