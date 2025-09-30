/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 04:33:49 by ep                #+#    #+#             */
/*   Updated: 2025/09/11 04:52:42 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void	solve(int *count, int len, int pos, char *s)
{
	int	c;

	if (pos == len)
	{
		s[pos] = 0;
		puts(s);
		return ;
	}
	c = 0;
	while (c < 256)
	{
		if (count[c])
		{
			s[pos] = (char)c;
			--count[c];
			solve(count, len, pos + 1, s);
			++count[c];
		}
		c++;
	}
}

int	main(int ac, char **av)
{
	int	count[256] = {0};
	int	len;
	int	i;

	if (ac != 2 && av[1][0] == 0)
		return (1);
	len = ft_strlen(av[1]);
	i = 0;
	while (i < len)
	{
		++count[(unsigned char)av[1][i]];
		i++;
	}
	solve(count, len, 0, av[1]);
	return (0);
}
