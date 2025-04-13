#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	subs_len;

	subs_len = 0;
	i = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + subs_len] && subs_len < len)
		subs_len++;
	subs = malloc(sizeof(char) * (subs_len + 1));
	if (subs == NULL)
		return (NULL);
	while (i < subs_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	unsigned int	start;
	size_t	len;

	start = ft_atoi(argv[2]);
	len = ft_atoi(argv[3]);
	printf("subs : %s", ft_substr(argv[1], start, len));
	return (0);
}*/

int	main(void)
{
	printf("subs : %s", ft_substr('\0', 0, 1));
	return (0);
}
