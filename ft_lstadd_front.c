#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{ 
    if (!new)
		return  ;
    new->next = *lst;  // Yeni elemanın next öğesini, mevcut başa işaret eden lst değişkeniyle ilişkilendirin
    *lst = new;  // lst değişkenini, yeni oluşturulan elemana işaret eden değişkene atayın
}