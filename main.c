#include "src/ft_printf.h"

int	main(void)
{
	// ft_printf("digit = %*d, char = %c\n", 5, 33, 'G');
	// ft_printf("percent = %%\n");
	ft_printf("percent = %5%\n");
	ft_printf("percent = %05%\n");
	ft_printf("percent = %-05%\n");
	ft_printf("percent = %-5%\n");
	return (0);
}
