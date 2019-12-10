/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:04:26 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 16:13:35 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_neg(t_form *form, int *i)
{
	if (*i < 0)
	{
		*i *= -1;
		form->width--;
	}
}

void			ft_display_prec(t_form *form, int *i, int *gap, char **s)
{
	int		neg_i;

	neg_i = 0;
	if (form->conv == 'd')
		neg_i = *i;
	if (form->precision == 0 && *i == 0)
	{
		*s = ft_strdup("");
		*gap = 0;
	}
	else if (form->precision > 0)
	{
		if (form->conv == 'd')
		{
			ft_neg(form, i);
			*s = ft_itoa(*i);
		}
		*gap = ft_strlen(*s);
		*s = ft_strjoin(fill(gap, form->precision, '0'), *s);
		if (neg_i < 0)
			*s = ft_strjoin("-", *s);
	}
}
