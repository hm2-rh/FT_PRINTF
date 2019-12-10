/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:59:28 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 16:09:49 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_display_percent(t_form *form)
{
	char	*s;
	int		gap;

	s = "%";
	gap = 1;
	if (form->flag[0] == '-' && form->width > gap)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->flag[1] == '0' && form->width > gap)
		s = ft_strjoin(fill(&gap, form->width, '0'), s);
	else if (form->flag[0] != '-' && form->width > gap)
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	form->count += ft_strlen(s);
	ft_putstr(s);
}
