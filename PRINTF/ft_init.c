/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:22:19 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/10 09:23:38 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_form *form)
{
	form->count = 0;
	form->pos = 0;
	form->flags = "-0";
	form->convs = "scdipuxX%";
	form->flag[0] = '\0';
	form->flag[1] = '\0';
	form->conv = '\0';
	form->precision = -1;
	form->width = 0;
	form->pos = 0;
}
