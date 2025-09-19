
#include <stdio.h>
#include <stdlib.h>
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

char	*ft_get_input(void)
{
	char	*str = NULL;
	char	*buf = malloc(3);
	char	*tmp = NULL;
	int	old_len = 0;
	int	new_len = 0;
	int	bytes_r;

	if (!buf)
		return (perror("malloc error"), NULL);

	while ((bytes_r = read(0, buf, 2)) > 0)
	{
		buf[bytes_r] = '\0';
		new_len = old_len + bytes_r;
		tmp = realloc(str, new_len + 1);
		if (!tmp)
		{
			free(str);
			free(buf);
			return (perror("realloc error"), NULL);
		}
		str = tmp;
		for (int i = 0; i < bytes_r; i++)
			str[old_len + i] = buf[i];
		// printf("str: %s\n", str);
		old_len = new_len;
		str[old_len] = '\0';
	}
	free(buf);
	if (bytes_r == -1)
	{
		free(str);
		return (perror("read error"), NULL);
	}
	if (!str)
		return (perror("empty input"), NULL);
	return str;
}

void	ft_filter_and_print(char *str, char *filter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] != filter[j])
			write(1, &str[i++], 1);
		while (str[i] && filter[j] && str[i + j] == filter[j])
			j++;
		if (j == ft_strlen(filter))
		{
			while (j > 0)
			{
				write(1, "*", 1);
				i++;
				j--;
			}
		}
		else
		{
			while (j > 0)
			{
				write(1, &str[i++], 1);
				j--;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
		return (perror("filter must take one argument"), 1);
	str = ft_get_input();
	// printf("input: %s", str);
	fflush(STDIN_FILENO);
	ft_filter_and_print(str, argv[1]);
	free(str);
	return (0);
}
