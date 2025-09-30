/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 05:35:51 by ep                #+#    #+#             */
/*   Updated: 2025/09/11 06:04:20 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int	is_found(char *in, char *f, int i)
{
	int	j;

	j = 0;
	while (in[i] && f[j])
	{
		if (in[i] == f[j])
		{
			i++;
			j++;
		}
		else
			break ;
	}
	if (f[j] == 0)
		return (1);
	return (0);
}

void	filter(char *in, char *f)
{
	int	i;
	int	len;

	len = strlen(f);
	i = 0;
	while (in[i])
	{
		len = strlen(f);
		if (in[i] == f[0] && is_found(in, f, i) == 1)
		{
			while (len > 0)
			{
				write(1, "*", 1);
				len--;
			}
			i = i + strlen(f);
		}
		else
		{
			write(1, &in[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	*in_buf;
	char	buf[BUFFER_SIZE];
	char	*new_buf;
	int		total;
	int		r;

	if (ac != 2 && av[2][1] == 0)
		return (1);
	total = 0;
	in_buf = NULL;
	while ((r = read(0, buf, BUFFER_SIZE)) > 0)
	{
		new_buf = realloc(in_buf, total + r + 1);
		if (!new_buf)
		{
			perror("Error");
			free(in_buf);
			return (1);
		}
		in_buf = new_buf;
		memmove(in_buf + total, buf, r);
		total = total + r;
	}
	if (r < 0)
	{
		perror("Error");
		free(in_buf);
		return (1);
	}
	if (!total)
		return (1);
	in_buf[total] = 0;
	filter(in_buf, av[1]);
	return (0);
}
