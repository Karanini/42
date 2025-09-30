/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 04:53:15 by ep                #+#    #+#             */
/*   Updated: 2025/09/11 05:12:23 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned long	mask;

void	print_soluce(int n, int *q)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", q[i]);
		i++;
	}
	printf("\n");
}

void	solve(int n, int *q, int col, mask rows, mask diag1, mask diag2)
{
	int		row;
	mask	rows_mask;
	mask	diag1_mask;
	mask	diag2_mask;

	if (col == n)
	{
		print_soluce(n, q);
		return ;
	}
	row = 0;
	while (row < n)
	{
		rows_mask = 1UL << row;
		diag1_mask = 1UL << (row + col);
		diag2_mask = 1UL << (row - col + n - 1);
		if (!(rows & rows_mask) && !(diag1 & diag1_mask)
			&& !(diag2 & diag2_mask))
		{
			q[col] = row;
			solve(n, q, col + 1, rows | rows_mask, diag1 | diag1_mask,
				diag2 | diag2_mask);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	q[32];

	if (ac != 2)
		return (1);
	solve(atoi(av[1]), q, 0, 0, 0, 0);
	return (0);
}
