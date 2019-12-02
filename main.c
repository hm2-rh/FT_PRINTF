#include <stdio.h>
#include <stdlib.h>
#include "PRINTF/ft_printf.h"

int		main()
{
	char *s = "hamza";
	int d = 133742;
	int i = printf("___printf: |%8s| |%06d| |%p| |%X|", s, d, &d, d);
	printf("\n");
	int ii = ft_printf("ft_printf: |%8s| |%5d| |%p| |%X|", s, d, &d, d);
	printf("\n");
	printf("printf: %d\nft_printf: %d\n", i, ii);
	printf("%s\n", ft_puthex_upper(d));
}
