/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:14:17 by ep                #+#    #+#             */
/*   Updated: 2025/09/11 04:32:26 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	par_to_solv(char *s)
{
	int	i;
	int	open;
	int	close;

	if (!s)
		return (0);
	i = 0;
	open = 0;
	close = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	solve(char *s, int len, int to_solve, int solved, int pos)
{
	char	c;

	if (pos == len || to_solve == solved)
	{
		if (!par_to_solv(s) && to_solve == solved)
			puts(s);
		return ;
	}
	c = s[pos];
	s[pos] = ' ';
	solve(s, len, to_solve, solved + 1, pos + 1);
	s[pos] = c;
	solve(s, len, to_solve, solved, pos + 1);
}

int	main(int ac, char **av)
{
	int	len;
	int	to_solve;

	if (ac != 2 && av[1][0] == 0)
		return (1);
	len = ft_strlen(av[1]);
	to_solve = par_to_solv(av[1]);
	solve(av[1], len, to_solve, 0, 0);
	return (0);
}
