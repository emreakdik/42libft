extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_isdigit\t: ")

	/* 1 */ check(!ft_isdigit('0' - 1)); showLeaks();
	/* 2 */ check(ft_isdigit('0')); showLeaks();
	/* 3 */ check(!ft_isdigit('9' + 1)); showLeaks();
	/* 4 */ check(ft_isdigit('9')); showLeaks();
	write(1, "\n", 1);
	return (0);
}