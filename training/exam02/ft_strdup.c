
#include<stdlib.h>

int	ft_strlen(unsigned char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	unsigned char 	*s;
	unsigned int	s_len;
	char		*res;
	unsigned int	i;

	i = 0;
	s = (unsigned char *)str;
	s_len = ft_strlen(s);
	res = malloc(sizeof(char) * (s_len + 1));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

#include<stdio.h>
int	main(int ac, char *av[])
{
	(void)ac;
	char	*dup = ft_strdup(av[1]);
	printf("%s\n", dup);
	return (0);
}
