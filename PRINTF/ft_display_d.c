/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:19:23 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 12:55:09 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	neg_d_with_zero(t_form *form, int *i, int *gap, char **s)
{
	char *tmp;

	*i *= -1;
	*s = ft_strjoin(fill(gap, form->width, '0'), *s + 1);
	tmp = *s;
	*s = ft_strjoin("-", *s);
	free(tmp);
	tmp = NULL;
}

void			ft_display_d(t_form *form)
{
	int		i;
	char	*s;
	char	*tmp;
	int		gap;

	i = va_arg(form->args, int);
	s = ft_itoa(i);
	gap = ft_strlen(s);
	ft_display_prec(form, &i, &gap, &s);
	tmp = s;
	if (form->flag[0] == '-' && form->width > 0)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->flag[1] == '0' && form->width > gap && form->precision < 0)
	{
		if (i < 0)
			neg_d_with_zero(form, &i, &gap, &s);
		else
			s = ft_strjoin(fill(&gap, form->width, '0'), s);
	}
	else if (form->width > 0 && form->flag[0] != '-')
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
