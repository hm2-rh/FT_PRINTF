#include "ft_printf.h"

void	ft_prec_handler(const char *c, void *val, int *count, int *i)
{
	int		prec;
	int		ref;

	prec = ft_atoi(c);
	ref = prec - ft_strlen((char *)val);
	while (ft_isdigit(*c))
	{
		*i += 1;
		c++;
	}
	while (ref--)
	{
		ft_putchar(' ');
		*count += 1;
	}
	ft_conv_handler(c, val, count, i);
}
