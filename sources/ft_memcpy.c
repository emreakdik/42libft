/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:35:57 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/12 15:52:25 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

//  #include <stdio.h>

//  int	main()
//  {
//  	char src[] = "Emre Akdik";
//  	char dest[100];

//  	ft_memcpy(&src[2], src, 9);
//  	printf("%s", dest);
//  }

// Dest dizisine, src dizisini n değeri kadar kopyalar ve desti döndürür.