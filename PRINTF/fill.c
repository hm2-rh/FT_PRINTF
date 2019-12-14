/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:59:26 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/13 17:50:06 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill(int *gap, int width, int c)
{
	int		len;
	int		index;
	char	*s;

	index = 0;
	len = width - *gap;
	if (len < 0)
		len = 0;
	s = malloc(len + 1);
	while (index < len)
	{
		s[index++] = c;
		*gap += 1;
	}
	s[index] = '\0';
	return (s);
}
