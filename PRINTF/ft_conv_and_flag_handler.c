/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_and_flag_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:08 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 15:20:04 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_isconv(const char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' ||
			c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

int	ft_isflag(const char c)
{
	if (c == '*' || c == '.' || c == '0' || c == '-')
		return (1);
	return (0);
}

void		ft_conv_and_flag_handler(const char *c, va_list arg, int *count,
			int *i)
{
	void *val;

	val = va_arg(arg, void *);
	if (ft_isflag(*c))
		ft_flag_handler(c, val, count, i);
	if (ft_isdigit(*c) && *c != '0')
		ft_width_handler(c, val, count, i);
	else if (ft_isconv(*c))
		ft_conv_handler(c, val, count, i);
}
