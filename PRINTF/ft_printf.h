#ifndef PRINTF_H
# define PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef	struct	s_form
{
	char		*copy;
	va_list		args;
	size_t		count;
	int			pos;
	int			precision;
	int			width;
	char		*flags;
	char		*convs;
	char		flag[2];
	char		conv;
}				t_form;

int				ft_printf(const char *format, ...);

void			ft_putchar(int c);
void			ft_putstr(char *s);
void			ft_putnbr(int nbr);
char			*ft_puthex_lower(unsigned long u_nbr);
char			*ft_puthex_upper(unsigned long u_nbr);
char			*ft_putunsigned(int nbr);
char			*ft_putptr(void * ui);
char			*ft_strncpy(char *dest, const char *src, int n);

void			ft_init(t_form *form);

int				ft_handler(t_form *form);
void			ft_handle_flags(t_form *form);
void			ft_handle_width(t_form *form);
void			ft_handle_precision(t_form *form);
void			ft_handle_conv(t_form *form);

void			ft_display_results(t_form *form);
void			ft_display_c(t_form *form);
//void			ft_display_s(t_form *form);
void			ft_display_d(t_form *form);
//void			ft_display_u(t_form *form);
//void			ft_display_x(t_form *form);
//void			ft_display_X(t_form *form);
//void			ft_display_p(t_form *form);

#endif
