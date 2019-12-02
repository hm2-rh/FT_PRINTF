/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:39 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 16:42:27 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_arg_len(const char *c, void *val)
{
	if (*c == 'c')
		return (1);
	else if (*c == 's')
	{
		return (ft_strlen((char *)val));
	}
	else if (*c == 'd' || *c == 'i')
		return (ft_strlen(ft_itoa((int)val)));
	else if (*c == 'x')
		return (ft_strlen(ft_puthex_lower((int)val)));
	else if (*c == 'X')
		return (ft_strlen(ft_puthex_upper((int)val)));
	else if (*c == 'u')
		return (ft_strlen(ft_putunsigned((int)val)));
	else if (*c == 'p')
		return (ft_strlen(ft_putptr(val)));
	return (0);
}

void		ft_width_handler(const char *c, void *val, int *count, int *i)
{
	int		prec;
	int		ref;

	prec = ft_atoi(c);

	while (ft_isdigit(*c))
	{
		*i += 1;
		c++;
	}
	ref = prec - ft_arg_len(c, val);
	if (ref > 0)
	{
		while (ref--)
		{
			ft_putchar(' ');
			*count += 1;
		}
	}
	ft_conv_handler(c, val, count, i);
}
