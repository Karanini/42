#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *s_c;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	s_c = malloc(sizeof(char) * (s_len + 1));
	if (s_c == NULL)
		return (NULL);
	while (s[i])
	{
		s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}
