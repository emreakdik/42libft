/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:17:55 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/20 00:13:54 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	unsigned int	c;
	unsigned int	d;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize <= ft_strlen(dest))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dest);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
		dest[c++] = src[d++];
	dest[c] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}

// int	main(){

// 	char dst[] = "Emre";
// 	char src[] = "Akdik";

// 	// printf("%p %p", dst, src);
	// printf("%lu\n", ft_strlcat(dst, src, 30);
// 	// printf("%s\n", dst);
// 	 // printf("%lu\n", strlcat(dst, src, 5));
// 	// printf("%s", dst);
// }