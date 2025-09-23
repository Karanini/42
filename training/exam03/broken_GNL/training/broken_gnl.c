#include "broken_gnl.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c) //ajout condition s[i]
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n > 0) // decrementation de n dans la boucle et non directement ici
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
		
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if (!s) // ajout protection
		return (0); 
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	if (dest > src)
// 		return (ft_memcpy(dest, src, n));
// 	else if (dest == src)
// 		return (dest);
// 	size_t	i = ft_strlen((char *)src) - 1;
// 	while (i >= 0)
// 	{
// 		((char *)dest)[i] = ((char *)src)[i];
// 		i--;
// 	}
// 	return (dest);
// }

void	ft_free()
{
	
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;

	char	*tmp = ft_strchr(b, '\n');
	if (fd < 0) //ajout protection fd incorrect
		return (NULL);
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		int	read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n'); //ajout maj de tmp
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int	main(void)
{
	char	*ret = NULL;
	char	*b = "";

	str_append_str(&ret, b);
	printf("ret: %s\n", ret);
	return (0);
}
