/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:04:26 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 12:40:28 by hrhirha          ###   ########.fr       */
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

static	int		null_prec(t_form *form, int *i, int *gap, char **s)
{
	int		neg_i;

	neg_i = 0;
	if ((form->conv == 'd' || form->conv == 'i') && *i < 0)
		neg_i = *i;
	if (form->precision == 0 && *i == 0)
	{
		free(*s);
		*s = ft_strdup("");
		*gap = 0;
	}
	return (neg_i);
}

static	void	check_neg_num(t_form *form, int *i, char **s)
{
	char *tmp;

	tmp = NULL;
	if (*i < 0 && (form->conv == 'd' || form->conv == 'i'))
	{
		ft_neg(form, i);
		free(*s);
		*s = ft_itoa(*i);
	}
}

void			ft_display_prec(t_form *form, int *i, int *gap, char **s)
{
	char	*tmp;
	int		neg_i;
	char	*tmp1;

	neg_i = null_prec(form, i, gap, s);
	if (form->precision > 0)
	{
		check_neg_num(form, i, s);
		*gap = ft_strlen(*s);
		tmp = *s;
		tmp1 = fill(gap, form->precision, '0');
		*s = ft_strjoin(tmp1, *s);
		free(tmp);
		free(tmp1);
		if (neg_i < 0)
		{
			tmp = *s;
			*s = ft_strjoin("-", *s);
			free(tmp);
		}
	}
}
