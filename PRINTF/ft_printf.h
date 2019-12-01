#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int nbr);
int		ft_puthex_lower(int nbr);
int		ft_puthex_upper(int nbr);
int		ft_putunsigned(int nbr);
int		ft_putptr(void *ptr);
void	ft_conv_and_flag_handler(const char *c, va_list arg, int *count, int *i);
void	ft_conv_handler(const char *c, void *val, int *count, int *i);
void	ft_prec_handler(const char *c, void *val, int *count, int *i);
//void	ft_flag_handler(const char *c, va_list arg, int *count, int *i);

#endif
