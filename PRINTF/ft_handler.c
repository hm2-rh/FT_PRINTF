/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:22:03 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 15:55:02 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
