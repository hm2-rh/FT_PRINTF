/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:19:33 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/11 14:11:20 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_malloc_len(unsigned long u_nbr)
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

char		*ft_hex(unsigned long u_nbr)
{
	char			*digits;
	char			*str;
	int				i;

	digits = "0123456789abcdef";
	i = ft_malloc_len(u_nbr);
	if (!(str = malloc(i + 1)))
		return (NULL);
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

char		*ft_putptr(void *ptr)
{
	char *s;
	char *tmp;

	tmp = ft_hex((unsigned long)ptr);
	s = ft_strjoin("0x", tmp);
	free(tmp);
	return (s);
}
