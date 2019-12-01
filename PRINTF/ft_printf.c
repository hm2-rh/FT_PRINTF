/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:15:08 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 14:15:18 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
			ft_conv_and_flag_handler(&format[i], arg, &count, &i);
		else if (format[i])
		{
			ft_putchar(format[i++]);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
