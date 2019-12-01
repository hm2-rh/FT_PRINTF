#include "ft_printf.h"

int		ft_putunsigned(int nbr)
{
	unsigned int	u_nbr;
	static int		count;

	u_nbr = nbr;
	if (u_nbr < 10)
	{
		ft_putchar((u_nbr % 10) + 48);
		count++;
	}
	else
	{
		count++;
		ft_putunsigned(u_nbr / 10);
		ft_putchar((u_nbr % 10) + 48);
	}
	return (count);
}
