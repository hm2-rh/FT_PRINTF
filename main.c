#include <stdio.h>
#include <stdlib.h>
#include "PRINTF/ft_printf.h"

int		main()
{
	char *s = "howdy";
	int d = 42;
	int i = printf("___printf: |%3c| |%-9.3s| |%015.5d| |%-4%| |%20p| |%016.13u| |%X|", 's', s, d, s, d, d);
	printf("\n");
	int ii = ft_printf("ft_printf: |%3c| |%-9.3s| |%015.5d| |%-4%| |%20p| |%016.13u| |%X|", 's', s, d, s, d, d);
	printf("\n");
	printf("___printf: %d\nft_printf: %d\n", i, ii);
}
