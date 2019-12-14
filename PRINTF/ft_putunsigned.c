/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:20:04 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 11:18:37 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_malloc_len(unsigned int u_nbr)
{
	int ret;

	ret = 0;
	while (u_nbr != 0)
	{
		u_nbr /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_putunsigned(int nbr)
{
	unsigned int	u_nbr;
	char			*str;
	int				i;

	u_nbr = nbr;
	i = ft_malloc_len(u_nbr);
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	if (u_nbr == 0)
		str[i--] = '0';
	while (i-- >= 0 && u_nbr != 0)
	{
		str[i] = (u_nbr % 10) + 48;
		u_nbr /= 10;
	}
	return (str);
}
