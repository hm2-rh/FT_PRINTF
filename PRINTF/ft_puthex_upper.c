/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:18:28 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 14:11:57 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_malloc_len(unsigned u_nbr)
{
	int ret;

	ret = 0;
	while (u_nbr != 0)
	{
		u_nbr /= 16;
		ret++;
	}
	return (ret);
}

char		*ft_puthex_upper(unsigned u_nbr)
{
	char			*digits;
	char			*str;
	int				i;

	digits = "0123456789ABCDEF";
	i = ft_malloc_len(u_nbr);
	str = malloc(i + 1);
	str[i] = '\0';
	if (u_nbr == 0)
		str[i--] = digits[0];
	while (i-- >= 0 && u_nbr != 0)
	{
		str[i] = digits[u_nbr % 16];
		u_nbr /= 16;
	}
	return (str);
}
