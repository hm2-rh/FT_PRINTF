#include "ft_printf.h"

static	void	ft_treatement(t_form *form)
{
	ft_handle_flags(form);
	ft_handle_width(form);
	ft_handle_precision(form);
	ft_handle_conv(form);
	ft_display_results(form);
}

int				ft_handler(t_form *form)
{
	while (form->copy[form->pos])
	{
		if (form->copy[form->pos] == '%')
		{
			form->pos++;
			ft_treatement(form);
		}
		else
		{
			ft_putchar(form->copy[form->pos]);
			form->count++;
		}
		form->pos++;
	}
	return (form->count);
}
