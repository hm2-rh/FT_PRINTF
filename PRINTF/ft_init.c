#include "ft_printf.h"

void		ft_init(t_form *form)
{
	form->count = 0;
	form->pos = 0;
	form->flags = "-0";
	form->convs = "scdipuxX%";
	form->flag[0] = '\0';
	form->flag[1] = '\0';
	form->conv = '\0';
	form->precision = -1;
	form->width = 0;
	form->pos = 0;
}
