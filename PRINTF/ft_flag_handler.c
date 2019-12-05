/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:46:18 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/05 23:23:10 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_result(t_flag *flag, const char *c)
{
	char	*pad;
	int		num;
	int		index;
	int		fill;

	fill = ' ';
	index = 0;
	num = flag->width - (int)ft_strlen(flag->str);
	pad = ft_calloc(1, 1);
	if ((*c == 'd' || *c == 'x' || *c == 'X') && num > 0)
	{
		pad = malloc(num + 1);
		if (flag->dot == 1 || flag->zero == 1)
			fill = '0';
		while (index < num)
			pad[index++] = fill;
		pad[index] = '\0';
	}
	else if (*c == 's' && num < 0)
	{
		free(pad);
		pad = malloc(flag->width);
		pad = ft_strncpy(pad, flag->str, flag->width);
		flag->str = "";
	}
	return (pad);
}

void	ft_width(t_flag *flag, const char *c, int *i, void *val)
{
	if (ft_isdigit(*c))
	{
		flag->width = ft_atoi(c);
		while (ft_isdigit(*c))
		{
			*i += 1;
			c++;
		}
	}
	else if (*c == '*')
	{
		flag->width = (int)val;
		*i += 1;
		c++;
	}
	flag->str = ft_conv_handler(c, val);
	if (flag->str == NULL)
		flag->str = "(null)";
}

void	ft_check_flag(t_flag *flag, const char *c, int *i)
{
	if (*c == '.')
		flag->dot = 1;
	else if (*c == '0')
		flag->zero = 1;
	else if (*c == '-')
		flag->minus = 1;
	*i += 1;
}

char	*ft_flag_handler(const char *c, void *val, int *i)
{
	t_flag	*flag;
	char	*res;
	char	*just;

	flag = malloc(sizeof(t_flag));
	res = NULL;
	just = NULL;
	while (*c == '.' || *c == '0' || *c == '-')
		ft_check_flag(flag, c++, i);
	if (*c == 's')
		flag->str = "";
	else
		ft_width(flag, c, i, val);
	just = ft_result(flag, ++c);
	if (flag->str[0] == '-' && flag->dot == 1 &&
		flag->width > (int)ft_strlen(flag->str))
	{
		just = ft_strjoin("-", just);
		flag->str[0] = '0';
	}
	res = ft_strjoin(just, flag->str);
	return (res);
}
