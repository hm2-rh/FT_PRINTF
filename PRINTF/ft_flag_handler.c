#include "ft_printf.h"

void	ft_flag_handler(const char *c, void *val, int *count, int *i)
{
	if (*c == '*')
	{
		int p = (int)val;
		p += 0;
		*count += 0;
		*i += 0;
	}
}
