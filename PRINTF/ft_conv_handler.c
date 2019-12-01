#include "ft_printf.h"

void	ft_conv_handler_ext(const char *c, int *count, void *val)
{
	if (*c == 'x')
		*count += ft_puthex_lower((int)val);
	else if (*c == 'X')
		*count += ft_puthex_upper((int)val);
	else if (*c == 'u')
		*count += ft_putunsigned((int)val);
	else if (*c == 'p')
		*count += ft_putptr(val);
}

void	ft_conv_handler(const char *c, void *val, int *count, int *i)
{
	char *s;

	if (*c == 'c')
	{
		ft_putchar((char)val);
		*count += 1;
	}
	else if (*c == 's')
	{
		*count += ft_strlen((char *)val);
		ft_putstr((char *)val);
	}
	else if (*c == 'd' || *c == 'i')
	{
		s = ft_itoa((int)val);
		*count += ft_strlen(s);
		ft_putstr(s);
	}
	ft_conv_handler_ext(c, count, val);
	*i += 1;
}
