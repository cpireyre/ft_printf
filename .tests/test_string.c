#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("!%38.12ls!\n", L"(╯°□°)╯︵ ┻━┻ ︵ ╯(°□° ╯)");
	printf("!%38.12ls!\n", L"(╯°□°)╯︵ ┻━┻ ︵ ╯(°□° ╯)");
	return (0);
}
