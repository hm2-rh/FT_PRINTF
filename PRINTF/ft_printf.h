/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:15:53 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 16:42:40 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int nbr);
char	*ft_puthex_lower(int nbr);
char	*ft_puthex_upper(int nbr);
char	*ft_putunsigned(int nbr);
char	*ft_putptr(void *ptr);
void	ft_conv_and_flag_handler(const char *c, va_list arg,
		int *count, int *i);
void	ft_conv_handler(const char *c, void *val, int *count, int *i);
void	ft_width_handler(const char *c, void *val, int *count, int *i);
void	ft_flag_handler(const char *c, void *val, int *count, int *i);

#endif
