/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_and_flag_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:08 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/05 20:28:55 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconv(const char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' ||
			c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

static	int	ft_isflag(const char c)
{
	if (c == '*' || c == '.' || c == '0' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

void		ft_conv_and_flag_handler(const char *c, va_list arg, int *count,
			int *i)
{
	void *val;
	char *str;

	str = NULL;
	val = va_arg(arg, void *);
	if (ft_isflag(*c))
	{
		str = ft_flag_handler(c, val, i);
		*count += ft_strlen(str);
		ft_putstr(str);
		*i += 1;
	}
	else if (ft_isconv(*c))
	{
		str = ft_conv_handler(c, val);
		if (*str == '\0' && *c == 'c')
			*count += 1;
		*count += ft_strlen(str);
		ft_putstr(str);
		*i += 1;
	}
}
