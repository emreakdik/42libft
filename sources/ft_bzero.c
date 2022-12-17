/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:33:29 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/07 01:05:53 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i;
// 	char str[] = "emreakdik";
// 	i = ft_strlen(str);
// 	ft_bzero(str, 4);
// 	write(1,&str,i);
// 	return 0;
// }