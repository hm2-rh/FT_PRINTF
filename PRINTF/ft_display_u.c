/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:12:58 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 11:17:01 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	neg_width(t_form *form)
{
	if (form->width < 0)
	{
		form->flag[0] = '-';
		form->width *= -1;
	}
}

void			ft_display_u(t_form *form)
{
	int		i;
	char	*s;
	char	*tmp;
	int		gap;

	tmp = NULL;
	i = va_arg(form->args, int);
	s = ft_putunsigned(i);
	if (i == 0)
	{
		tmp = s;
		s = ft_strdup("0");
		free(tmp);
	}
	gap = ft_strlen(s);
	ft_display_prec(form, &i, &gap, &s);
	neg_width(form);
	if (form->flag[0] == '-' && form->width > 0)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->flag[1] == '0' && form->width > gap && form->precision < 0)
		s = ft_strjoin(fill(&gap, form->width, '0'), s);
	else if (form->width > 0 && form->flag[0] != '-')
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
