#include "src/ft_printf.h"

int	main(void)
{
	int p;

	p = 34;
	ft_printf("%2p\n", &p);
	printf("%2p\n", &p);
	return (0);
}
