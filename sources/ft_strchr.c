/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:21:30 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/06 17:21:31 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (c == s[i])
		return ((char *)s);
	return (0);
}

// s dizisi içinde c karakterini arar. Bulduğu an olduğu indeksin adresi çevirir.