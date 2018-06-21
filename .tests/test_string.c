#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	wchar_t	*dreppamig = L"fuck meeee";

	setlocale(LC_ALL, "");
	ft_putnbr_endl(printf("%C", 128150));
	return (0);
}
