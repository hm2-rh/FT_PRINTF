/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:19:23 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 12:10:16 by hrhirha          ###   ########.fr       */
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

static	void	zero_flag_and_noflag(t_form *form, int *i, int *gap, char **s)
{
	char *tmp;
	char *tmp1;

	tmp1 = NULL;
	if (form->flag[1] == '0' && form->width > *gap && form->precision < 0)
	{
		if (*i < 0)
			neg_d_with_zero(form, i, gap, s);
		else
		{
			tmp = *s;
			tmp1 = fill(gap, form->width, '0');
			*s = ft_strjoin(tmp1, *s);
			free(tmp1);
			free(tmp);
		}
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

void			ft_display_d(t_form *form)
{
	int		i;
	char	*s;
	char	*tmp;
	char	*tmp1;
	int		gap;

	i = va_arg(form->args, int);
	s = ft_itoa(i);
	gap = ft_strlen(s);
	ft_display_prec(form, &i, &gap, &s);
	if (form->flag[0] == '-' && form->width > 0)
	{
		tmp = s;
		tmp1 = fill(&gap, form->width, ' ');
		s = ft_strjoin(s, tmp1);
		free(tmp1);
		free(tmp);
	}
	zero_flag_and_noflag(form, &i, &gap, &s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
