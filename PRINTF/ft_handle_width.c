#include "ft_printf.h"

void	ft_handle_width(t_form *form)
{
	if (form->copy[form->pos] == '*')
	{
		form->width = va_arg(form->args, int);
		form->pos++;
	}
	if (ft_isdigit(form->copy[form->pos]))
		form->width = ft_atoi(&form->copy[form->pos]);
	while (ft_isdigit(form->copy[form->pos]))
		form->pos++;
}
