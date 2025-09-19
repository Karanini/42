
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*str;
	char	*buf;
	int	old_len;
	int	i;
	int	bytes_r;

	str = NULL;
	buf = malloc(3);
	bytes_r = read(0, buf, 2);
	buf[bytes_r] = '\0';
	if (bytes_r == -1)
		return (perror("read error"), 1);
	if (bytes_r == 0)
		return (perror("empty input"), 1);
	while (bytes_r > 0)
	{
		old_len = ft_strlen(str);
		i = 0;
		str = realloc(str, ft_strlen(buf));
		if (!str)
			return (1);
		while (i < bytes_r)
		{
			str[old_len + i] = buf[i];
			i++;
		}
		str[old_len + i] = '\0';
		bytes_r = read(0, buf, 2);
	}
	printf("input: %s", str);
	free(str);
	free(buf);
	return (0);
}	
	
