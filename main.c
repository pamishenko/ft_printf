#include "src/ft_printf.h"

int	main(void)
{
	int	p;

	p = 34;
	ft_printf("%2p\n", &p);
	printf("%2p\n", &p);
	ft_printf("%2s\n", "\nЭто тестовая строка\n");
	ft_printf("%1.1s", "aasf");
	return (0);
}
