#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

int ft_printf(char const *s, ...)
{
	va_list	args;
	int     total_len;

	total_len = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			total_len += handle_format_specifier(*s, args);
		}
		else
		{
			ft_putchar_fd(*s, 0);
			total_len++;
		}
		s++;
	}
	va_end(args);
	return (total_len);
}
int main(void)
{	

	int x = 1;
	printf("%x %p\n", 156, NULL);
	ft_printf("%x %p\n", 156, NULL);

}