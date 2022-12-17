#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
		while (n--)
			*((unsigned char *)(dst + n)) = *((unsigned char *)(dst + n));
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char dest[] = "Emreee";
// 	char srrc[] = "Akdik";

	
// 	ft_memmove(dest, srrc, 3);
// 	printf("%s", dest);
// // 	// memmove(dest, srrc, 3);
// // 	// printf("%s", dest);
// }