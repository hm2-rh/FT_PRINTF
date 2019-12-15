#include <stdio.h>
#include <stdlib.h>
#include "PRINTF/ft_printf.h"

int		main()
{
	//char *s = "howdy";
	//int d = 0;
	int i = printf("___printf: |%.p|", NULL);
	printf("\n");
	int ii = ft_printf("ft_printf: |%.p|", NULL);
	printf("\n");
	printf("___printf: %d\nft_printf: %d\n", i, ii);
}
