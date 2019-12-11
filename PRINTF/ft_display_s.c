/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:03:36 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 13:58:00 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_display_s(t_form *form)
{
	char	*s;
	int		gap;

	s = va_arg(form->args, char *);
	if (s == NULL)
		s = "(null)";
	if (form->precision == 0)
		s = "";
	gap = ft_strlen(s);
	if (form->precision < gap && form->precision > 0)
	{
		s = ft_substr(s, 0, form->precision);
		gap = ft_strlen(s);
	}
	if (form->flag[0] == '-' && form->width > gap)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->flag[0] != '-' && form->width > gap)
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	form->count += ft_strlen(s);
	ft_putstr(s);
}
