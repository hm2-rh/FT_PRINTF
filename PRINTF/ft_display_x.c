/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:08:30 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 14:53:57 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_display_x(t_form *form)
{
	int		i;
	char	*s;
	char	*tmp;
	int		gap;

	tmp = NULL;
	i = va_arg(form->args, unsigned);
	s = ft_puthex_lower(i);
	gap = ft_strlen(s);
	ft_display_prec(form, &i, &gap, &s);
	tmp = s;
	if (form->width < 0)
	{
		form->flag[0] = '-';
		form->width *= -1;
	}
	if (form->flag[0] == '-' && form->width > 0)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->flag[1] == '0' && form->width > gap && form->precision < 0)
		s = ft_strjoin(fill(&gap, form->width, '0'), s);
	if (form->width > 0 && form->flag[0] != '-')
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	free(tmp);
	form->count += ft_strlen(s);
	ft_putstr(s);
}
