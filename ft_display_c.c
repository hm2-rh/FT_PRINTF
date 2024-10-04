/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:19:03 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 12:41:12 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
