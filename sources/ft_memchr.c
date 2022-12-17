#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((void*)(s + i)); // s + i = s[i]
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = "Sami Guntepe";
// 	printf("%s", (char *)ft_memchr(s,'u',8));
// }

// s dizinde c karakterini arar ve bulduğunda olduğu adresi döndürür.
// ekran da c karakterinin adresinden sonrası çıktı verir.