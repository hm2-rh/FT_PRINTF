#include "ft_printf.h"

void	ft_display_c(t_form *form)
{
	int c;
	c = va_arg(form->args, int);

	if (form->flag[0] == '-')
	{
		ft_putchar(c);
		form->count++;
	}
	while (--form->width > 0)
	{
		ft_putchar(' ');
		form->count++;
	}
	if (form->flag[0] != '-')
	{
		ft_putchar(c);
		form->count++;
	}
}
