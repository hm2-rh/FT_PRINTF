#include "ft_printf.h"

int		ft_putptr(void *ptr)
{
	int p;
	int count;

	p = (int)ptr;
	count = 0;
	ft_putstr("0x");
	count = ft_puthex_lower(p) + 2;
	return (count);
}
