/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:21:22 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 15:54:38 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_conv(t_form *form)
{
	int i;

	i = 0;
	while (form->convs[i])
	{
		if (form->convs[i] == form->copy[form->pos])
		{
			form->conv = form->convs[i];
			break ;
		}
		i++;
	}
}
