/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:46:12 by yakdik            #+#    #+#             */
/*   Updated: 2022/12/19 15:55:54 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}

/*Bu C dilinde bir fonksiyondur ve bir karakter dizisinin başlangıç ve sonundaki belirli karakterleri siler. 
Örneğin, eğer "s1" karakter dizisi " abc " ve "set" karakter dizisi " " ise, bu fonksiyon "abc" dizisini döndürür.
İlk olarak, fonksiyon "s1" karakter dizisinin başındaki karakterleri tarar ve "set" karakter dizisinde bulunan herhangi bir karakter ile eşleştiğinde,
bu karakterleri atlar. Bunu yaparken, "ft_strchr" fonksiyonu kullanılır. Bu fonksiyon bir karakter dizisinde belirli bir karakter arar ve bulursa, 
karakterin bulunduğu dizinin başlangıç adresini döndürür. Eğer karakter bulunamazsa, NULL döndürür.
Sonra, fonksiyon "s1" karakter dizisinin sonundaki karakterleri tarar ve "set" karakter dizisinde bulunan herhangi bir karakter ile eşleştiğinde,
bu karakterleri atlar. Bu işlem aynı şekilde "ft_strchr" fonksiyonu kullanılarak yapılır.
Sonra, fonksiyon "len" adlı bir sayaç değişkeni kullanarak "s1" karakter dizisinin kalan uzunluğunu hesaplar. 
Ardından, "result" adlı bir karakter dizisi oluşturur ve "s1" dizisinin kalan kısmını bu diziye kopyalar. 
Son olarak, "result" dizisinin sonuna bir '\0' karakteri ekler ve bu diziyi döndürür. */



