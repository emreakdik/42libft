/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:22:34 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/20 14:35:53 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t amount, size_t n)
{
	void	*ptr;

	ptr = malloc(amount * n);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, amount * n);
	return (ptr);
}
