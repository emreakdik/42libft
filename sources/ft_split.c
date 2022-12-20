#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_make_words(char *word, char const *s, int j, int word_ln)
{
	int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[j - word_ln--];
	word[i] = 0;
	return (word);
}

static char	**ft_split_words(char **res, char const *s, char c, int word_ct)
{
	int	i;
	int	j;
	int	word_ln;

	i = 0;
	j = 0 ;
	word_ln = 0;
	while (s[j] && i < word_ct)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_ln++;
		}
		res[i] = (char *)malloc(sizeof(char) * (word_ln + 1));
		if (!res[i])
			return (0);
		ft_make_words (res[i], s, j, word_ln);
		word_ln = 0;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		word_ct;
	char	**res;

	if (s == 0)
		return (0);
	word_ct = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_ct + 1));
	if (!res)
		return (0);
	ft_split_words (res, s, c, word_ct);
	return (res);
}

// Bu fonksiyon, verilen bir dizide (s parametresi) belirli bir ayracı (c parametresi) kullanarak diziyi parçalara ayırır ve ayrıştırılmış parçaları bir dizi olarak döndürür. 

// int main(void) {
//   char **result = ft_split("Bu bir deneme metnidir", ' ');
//   int i;
//   for (i = 0; result[i] != NULL; i++) {
//     printf("%s\n", result[i]);
//   }

//   // Belleği serbest bırakalım
//   for (i = 0; result[i] != NULL; i++) {
//     free(result[i]);
//   }
//   free(result);

//   return 0;
// }