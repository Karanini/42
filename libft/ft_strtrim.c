#include "libft.h"
#include <stdio.h>

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_trim;
	size_t	end_trim;
	size_t	trim_len;
	char	*str_trim;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start_trim = 0;
	end_trim = ft_strlen(s1) - 1;
	while (ft_char_in_set(s1[start_trim], set) == 1)
		start_trim++;
	while (ft_char_in_set(s1[end_trim], set) == 1)
		end_trim--;
	if (start_trim > end_trim)
		return (ft_strdup(""));
	trim_len = end_trim - start_trim + 1;
	str_trim = ft_substr(s1, start_trim, trim_len);
	return (str_trim);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 3)
	{
		str = ft_strtrim(argv[1], argv[2]);
		printf("str : %s\n", str);
	}
	return (0);
}
