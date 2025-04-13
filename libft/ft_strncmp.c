#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while (s1b[i] && s2b[i] && s1b[i] == s2b[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (s1[i] - s2[i]);
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("res : %d\n", ft_strncmp(argv[1], argv[2], 5));	
	printf("res OG : %d\n", strncmp(argv[1], argv[2], 5));
	return (0);
}*/	
