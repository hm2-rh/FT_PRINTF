#include <stdio.h>
#include <stdlib.h>
#include "PRINTF/ft_printf.h"

/*char	*ft(t_flag *flag)
{
	char	*pad;
	int		num;
	int		i;

	i = 0;
	num = flag->width - (int)ft_strlen(flag->str);
	pad = malloc(num);
	while (i < num)
	{
		pad[i] = '0';
		i++;
	}
	return (pad);
}*/

int		main()
{
//	char *s = "tests";
//	int d = -42;
//	int i = printf("___printf: |%c| |%.3s| |%0.0d|", 'a', s, d);
//	printf("\n");
//	int ii = ft_printf("ft_printf: |%c| |%.3s| |%0.0d|", 'a', s, d);
//	printf("\n");
//	printf("printf: %d\nft_printf: %d\n", i, ii);
	ft_printf("%%|\n");
}
