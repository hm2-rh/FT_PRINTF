/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:21:55 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 11:39:13 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_p(t_form *form)
{
	void	*ptr;
	char	*s;
	char	*tmp;
	int		gap;

	ptr = va_arg(form->args, void *);
	s = ft_putptr(ptr);
	gap = ft_strlen(s);
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
