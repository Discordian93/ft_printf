char	*convert_hex_to_lowercase(char *hex_repr)
{
	char	*hex_og;

	hex_og = hex_repr;
	while (*hex_repr != '\0')
	{
		if (*hex_repr >= 'A' && *hex_repr <= 'F')
		{
			*hex_repr = *hex_repr - 'A' + 'a';
		}
		hex_repr++;
	}
	return (hex_og);
}