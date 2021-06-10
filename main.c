#include "src/ft_printf.h"

int	main(void)
{
	int p;

	p = 34;
	ft_printf("%23p\n", &p);
	printf("%23p\n", &p);
	return (0);
}
