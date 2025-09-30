/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 05:13:06 by ep                #+#    #+#             */
/*   Updated: 2025/09/11 05:35:05 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *s)
{
	int	c;

	if (!s)
		return (0);
	c = 0;
	while (s[c])
		c++;
	return (c);
}

char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	if (!s)
		return (NULL);
	d = malloc(ft_strlen(s)) + 1;
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	line[70000];
	static int	r = 0;
	static int	x = 0;
	int			y;

	y = 0;
	while (1)
	{
		if (x >= r)
		{
			r = read(fd, buf, BUFFER_SIZE);
			x = 0;
			if (r <= 0)
				break ;
		}
		line[y++] = buf[x++];
		if (buf[x] == '\n')
			break ;
	}
	line[y] = 0;
	if (y == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		// free(line);
	}
	printf("\n");
}
