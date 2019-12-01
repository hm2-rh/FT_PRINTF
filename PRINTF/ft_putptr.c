/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:19:33 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 16:45:49 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putptr(void *ptr)
{
	unsigned long	p;
	char *s;

	p = (unsigned long)ptr;
	s = ft_strjoin("0x", ft_puthex_lower(p));
	return (s);
}
