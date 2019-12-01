#include "ft_printf.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= 0 && nbr < 10)
			ft_putchar((nbr % 10) + 48);
		else
		{
			ft_putnbr(nbr / 10);
			ft_putchar((nbr % 10) + 48);
		}
	}
}
