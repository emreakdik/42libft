/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:21:49 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/20 10:33:52 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*tmp;

	tmp = s;
	i = ft_strlen(s);
	s = (s + i);
	while (*s != *tmp && (char)c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
