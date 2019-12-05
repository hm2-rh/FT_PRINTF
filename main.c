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
	t_flag *flag;

	flag = malloc(sizeof(t_flag));
	char *s = "test";
	int d = 42;
	int i = printf("___printf: |%c| |%.3s| |%.*x|", 'a', s, 7, d);
	printf("\n");
	int ii = ft_printf("ft_printf: |%c| |%.3s| |%.*x|", 'a', s, 7, d);
	printf("\n");
	printf("printf: %d\nft_printf: %d\n", i, ii);
	//printf("%s|\n", s);
}
