/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:59:28 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 13:00:29 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	zero_flag_and_noflag(t_form *form, int *gap, char **s)
{
	char *tmp;
	char *tmp1;

	tmp1 = NULL;
	if (form->flag[1] == '0' && form->width > *gap && form->precision < 0)
	{
		tmp = *s;
		tmp1 = fill(gap, form->width, '0');
		*s = ft_strjoin(tmp1, *s);
		free(tmp1);
		free(tmp);
	}
	if (form->width > 0 && form->flag[0] != '-')
	{
		tmp = *s;
		tmp1 = fill(gap, form->width, ' ');
		*s = ft_strjoin(tmp1, *s);
		free(tmp1);
		free(tmp);
	}
}

void			ft_display_percent(t_form *form)
{
	char	*s;
	char	*tmp;
	char	*tmp1;
	int		gap;

	s = ft_strdup("%");
	gap = 1;
	if (form->flag[0] == '-' && form->width > 0)
	{
		tmp = s;
		tmp1 = fill(&gap, form->width, ' ');
		s = ft_strjoin(s, tmp1);
		free(tmp1);
		free(tmp);
	}
	zero_flag_and_noflag(form, &gap, &s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
