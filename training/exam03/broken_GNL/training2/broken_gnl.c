#include "broken_gnl.h"
#include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c) //s[i] added
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n) //changed copy direction: from left to right
	//like the original memcpy to avoid memory overlaps
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if (!s) // added
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	int	i = (int)ft_strlen((char *)src) - 1;
	while (i >= 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i--;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	int		read_ret;
	// char	*update_b;

	// update_b = NULL;
	read_ret = -1;
	char	*newline_ptr = NULL; //mod: initializing at NULL
	while (!newline_ptr && read_ret != 0)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
		{
			if (ret) //added
				free(ret);
			return (NULL);
		}
		b[read_ret] = 0;
		if (read_ret == 0) // added: instructions if nothing else to read
		{
			if (ret && *ret)
				return (ret);
			free(ret);
			return (NULL);
		}
		newline_ptr = ft_strchr(b, '\n'); // added: updating newline_ptr
	}
	if (newline_ptr)
	{
		if (!str_append_mem(&ret, b, newline_ptr - b + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(b, newline_ptr + 1, ft_strlen(newline_ptr + 1) + 1); // +
		// newline_ptr + 1 because we copy the chars after the \n from newline_ptr to b
		// ft_strlen(newline_ptr + 1) + 1 because we include the '\0' at the end of newline_ptr
		// to eliminate the old chars from b
	}
	else
	{
		b[0] = '\0';
	}
	return (ret);
}

int main(void)
{
	int	fd;
	char *line;

	fd = open("../test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
