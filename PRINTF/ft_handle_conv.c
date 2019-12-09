#include "ft_printf.h"

void	ft_handle_conv(t_form *form)
{
	int i;

	i = 0;
	while (form->convs[i])
	{
		if (form->convs[i] == form->copy[form->pos])
		{
			form->conv = form->convs[i];
			break;
		}
		i++;
	}
}
