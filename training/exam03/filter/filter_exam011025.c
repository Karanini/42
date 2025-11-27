/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_exam011025.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:53:16 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/10/02 12:44:14 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_get_input_line(void);

int	main(int argc, char *argv[])
{
	char	*line;

	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	line = ft_get_input_line();
	if (!line)
		return (perror("Error: "), 1);
	printf("%s", line);
	free(line);
	return (0);
}

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

char	*ft_get_input_line(void)
{
	int		bytes_r;
	char	*buf;
	int		buf_size;
	char	*tmp;
	char	*line;
	int		line_len;

	buf_size = 3;
	line_len = 0;
	buf = malloc(sizeof(char) * (buf_size + 1));
	if (!buf)
		return (NULL);
	line = NULL;
	tmp = NULL;
	bytes_r = read(0, buf, buf_size);
	if (bytes_r == -1)
		return (free(buf), NULL);
	while (bytes_r)
	{
		buf[bytes_r] = 0;
		line_len = ft_strlen(line);
		tmp = realloc(line, sizeof(char) * (bytes_r + line_len + 1));
		if (!tmp)
		{
			if (line)
				free(line);
			return (free(buf), NULL);
		}
		memmove(tmp + line_len, buf, bytes_r);
		tmp[line_len + bytes_r] = 0;
		line = tmp;
		bytes_r = read(0, buf, buf_size);
		if (bytes_r == -1)
			return (free(line), free(buf), NULL);
	}
	// printf("buf: %s\n", buf);
	return (free(buf), line);
}
