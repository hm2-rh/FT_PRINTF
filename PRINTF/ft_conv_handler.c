/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:20 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/05 13:17:25 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_handler(const char *c, void *val)
{
	char *str;

	str = ft_calloc(1, 1);
	if (*c == 'c')
		*str = (char)val;
	else if (*c == 's')
	{
		str = (char *)val;
		if (str == NULL)
			str = "(null)";
	}
	else if (*c == 'd' || *c == 'i')
		str = ft_itoa((int)val);
	else if (*c == 'x')
		str = ft_puthex_lower((int)val);
	else if (*c == 'X')
		str = ft_puthex_upper((int)val);
	else if (*c == 'u')
		str = ft_putunsigned((int)val);
	else if (*c == 'p')
		str = ft_putptr(val);
	return (str);
}
