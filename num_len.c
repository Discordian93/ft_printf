int	num_len(int num)
{
	int	len;
	int	i;

	len = 0;
	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		len++;
		num = -num;
	}

	i = num;
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}