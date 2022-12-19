#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


// belirtilen dosya tanımlayıcısına (file descriptor) c karakterini yazar.
// file descriptor'u bir dosyanın ona ulaşmamız için ihtiyacımız olan kimlik numarası olarak düşünebiliriz.
// dosyalara ulaşırken 0-1-2 kullanarak erişimi çeşitlendirebiliriz. hatırla write(1, 'c', 1)