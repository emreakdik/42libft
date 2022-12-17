#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char *s1 = "Emre Akdik";
// 	char *s2 = "Emre Kakdik";

// 	printf("%d",ft_memcmp(s1,s2,9));
// }

// s1 vs s2 belleklerini n değeri kadar karşılaştırır.
// Değerler aynı ise 0 döndürür.
// Farklı karakter bulursa decimal farklarını döndürür.