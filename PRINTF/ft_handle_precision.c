/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:21:41 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 15:10:18 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_precision(t_form *form)
{
	if (form->copy[form->pos] == '.')
	{
		form->precision = 0;
		form->pos++;
		if (ft_isdigit(form->copy[form->pos]))
		{
			form->precision = ft_atoi(&form->copy[form->pos]);
			while (ft_isdigit(form->copy[form->pos]))
				form->pos++;
		}
		else if (form->copy[form->pos] == '*')
		{
			form->precision = va_arg(form->args, int);
			form->pos++;
		}
	}
}
