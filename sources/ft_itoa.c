#include "libft.h"

static int	ft_lennmb(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nmb;
	int		sign;
	int		lennmb;

	nmb = n;
	sign = 1;
	if (nmb < 0)
		sign = -1;
	nmb = sign * nmb;
	lennmb = ft_lennmb(nmb, sign);
	str = (char *)malloc(sizeof(char) * lennmb + 1);
	if (!str)
		return (0);
	str[lennmb] = '\0';
	while (--lennmb >= 0)
	{
		str[lennmb] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	int a = -300;
	printf("%d", a);
}*/