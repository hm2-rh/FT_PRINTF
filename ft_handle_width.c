/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:21:51 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 12:33:30 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_width(t_form *form)
{
	if (form->copy[form->pos] == '*')
	{
		form->width = va_arg(form->args, int);
		if (form->width < 0)
		{
			form->flag[0] = '-';
			form->width *= -1;
		}
		form->pos++;
	}
	if (ft_isdigit(form->copy[form->pos]))
		form->width = ft_atoi(&form->copy[form->pos]);
	while (ft_isdigit(form->copy[form->pos]))
		form->pos++;
}
