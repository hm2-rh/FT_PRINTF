/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:03:36 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 13:08:51 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	minus_flag_or_noglag(t_form *form, int *gap, char **s)
{
	char *tmp;
	char *tmp1;

	if (form->flag[0] == '-' && form->width > 0)
	{
		tmp = *s;
		tmp1 = fill(gap, form->width, ' ');
		*s = ft_strjoin(*s, tmp1);
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

void			ft_display_s(t_form *form)
{
	char	*str;
	char	*s;
	int		gap;

	str = va_arg(form->args, char *);
	if (str == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(str);
	if (form->precision == 0)
	{
		free(s);
		s = ft_strdup("");
	}
	gap = ft_strlen(s);
	if (form->precision < gap && form->precision > 0)
	{
		free(s);
		s = ft_substr(s, 0, form->precision);
		gap = ft_strlen(s);
	}
	minus_flag_or_noglag(form, &gap, &s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
