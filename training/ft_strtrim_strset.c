#include "libft.h"
#include <stdio.h>

// static void	ft_malloc_trim(char const *s1, char *trim,
//		size_t trim_len, size_t jump);
// mauvaise implementation de strtrim : la fonction trim toute la chaine set au debut et a la fin
// Par ex, si set == "abc" alors ca trime abc au debut et a la fin
// fonctionne que si set apparait une fois au debut et/ou a la fin.
// Si s1 == "32abcabc", trim == "32abc"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	nb_set;
	size_t	jump;
	size_t	trim_len;
	char	*trim;

	if (!s1)
		s1 = "";
	if (!set)
		set = "";
	set_len = ft_strlen(set);
	nb_set = 0;
	jump = 0;
	if (ft_strnstr(s1, set, set_len) == s1)
	{
		jump = set_len;
		nb_set++;
	}
	if (ft_strnstr((s1 + jump), set, ft_strlen(s1) - jump) == s1 + ft_strlen(s1)
		- set_len)
		nb_set++;
	trim_len = ft_strlen(s1) - (nb_set * set_len);
	trim = ft_substr(s1, jump, trim_len);
	// ft_malloc_trim(s1, trim, trim_len, jump);
	return (trim);
}

/*static void	ft_malloc_trim(char const *s1, char *trim,
		size_t trim_len, size_t jump)
{
	size_t	i;
	char	*str;

	i = 0;
	trim = malloc(sizeof(char) * (trim_len + 1));
	if (trim == NULL)
		return ;
	while (i < trim_len)
	{
		trim[i] = s1[jump + i];
		i++;
	}
	trim[i] = '\0';
}*/
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		str = ft_strtrim(argv[1], argv[2]);
		printf("str : %s\n", str);
	}
	return (0);
}
