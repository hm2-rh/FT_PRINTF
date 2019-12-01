#include "ft_printf.h"

int		ft_puthex_upper(int nbr)
{
	unsigned int	u_nbr;
	char			*digits;
	static int		count;

	u_nbr = nbr;
	digits = "0123456789ABCDEF";
	if (u_nbr < 16)
	{
		ft_putchar(digits[u_nbr % 16]);
		count++;
	}
	else
	{
		count++;
		ft_puthex_upper(u_nbr / 16);
		ft_putchar(digits[u_nbr % 16]);
	}
	return (count);
}
