#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}


/*
Bu fonksiyon, verilen "content" değerini içeren bir t_list yapısı oluşturur ve bu yapının bir örneğini döndürür.
Örnek oluşturulduktan sonra, "next" öğesi NULL olarak ayarlanır, ancak "content" öğesi verilen değerle doldurulur.
t_list yapısı, bir bağlı liste elemanı olarak kullanılabilecek bir yapıdır ve genellikle bir "content" öğesi ve bir "next" öğesi içerir.
"content" öğesi, elemanın içeriğini tutar ve "next" öğesi, bir sonraki elemana işaret eden bir bağlantı içerir.
ft_lstnew fonksiyonu, verilen bir değeri içeren bir t_list yapısı oluşturur ve bu yapının bir örneğini döndürür. 
Bu, bir bağlı liste elemanı oluşturmak için kullanılabilir ve daha sonra bu eleman bağlı listeye eklenebilir.
*/