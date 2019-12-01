#include "ft_printf.h"

int		ft_puthex_lower(int nbr)
{
	unsigned int	u_nbr;
	char			*digits;
	static int		count;

	u_nbr = nbr;
	digits = "0123456789abcdef";
	if (u_nbr < 16)
	{
		ft_putchar(digits[u_nbr % 16]);
		count++;
	}
	else
	{
		count++;
		ft_puthex_lower(u_nbr / 16);
		ft_putchar(digits[u_nbr % 16]);
	}
	return (count);
}
