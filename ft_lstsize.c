#include "libft.h"
//listin boyutunu bulur.
int	ft_lstsize(t_list *lst)
{ // argüman lst o an içine girilecek olan listeyi gösterir.
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)  // lst'nin next'i null olmadığı sürece
	{
		lst = lst->next; // listeye sıradaki liste atılır.
		i++; // i artırılır ve bu işlemler başa sararak devam eder.
	}
	return (i); // ne zaman ki sıradaki liste bulunmaz (yani nex null çıkar) o zaman artırılmış i return edilir.
}