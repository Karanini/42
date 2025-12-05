/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_training.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:21:16 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/12/05 16:46:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	BOARD_SIZE 4

void	ft_print_solution(int n, char board[BOARD_SIZE][BOARD_SIZE]);
void	ft_print_board(int n, char board[BOARD_SIZE][BOARD_SIZE]);
int		ft_valid_solution(char board[BOARD_SIZE][BOARD_SIZE], int row_test, int col_test, int n);

void	ft_recursive_queens(int row, int n, char board[BOARD_SIZE][BOARD_SIZE])
{
	if (row == n)
	{
		ft_print_solution(n, board);
		ft_print_board(n, board);
	}
	else
	{
		for (int col = 0; col < n; col++)
		{
			if (ft_valid_solution(board, row, col, n))
			{
				board[row][col] = 'Q';
				ft_recursive_queens(row + 1, n, board);
				board[row][col] = 'o';
			}
		}
	}
}

int		ft_valid_solution(char board[BOARD_SIZE][BOARD_SIZE], int row_test, int col_test, int n)
{
	row_test = 0;
	for (int row = 0; row < n - 1; row++)
	{
		if (board[row][col_test] == 'Q')
			return (0);
		// if (board[row][n - 1 - col_test] == 'Q')
		// 	return (0);
	}
	int i = 1;
	for (int row = col_test; row < n - 1; row++)
	{
		if (board[row][n - i] == 'Q')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_board(int n, char board[BOARD_SIZE][BOARD_SIZE])
{
	int	row;
	int	col;
	static int nb_solutions = 0;

	row = 0;
	col = 0;
	nb_solutions++;
	while (row < n)
	{
		while (col < n)
		{
			fprintf(stdout, "%c ", board[row][col]);
			col++;
		}
		fprintf(stdout, "\n");
		col = 0;
		row++;
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "nb_sol=%d", nb_solutions);
	fprintf(stdout, "\n\n");

}

void	ft_print_solution(int n, char board[BOARD_SIZE][BOARD_SIZE])
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (col < n)
	{
		while (row < n)
		{
			if (board[row][col] == 'Q')
				fprintf(stdout, "%d ", row);
			row++;
		}
		row = 0;
		col++;
	}
	fprintf(stdout, "\n");
}

void	ft_init_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
			board[row][col] = 'o';
	}
}

int	main (void)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	ft_init_board(board);
	ft_recursive_queens(0, BOARD_SIZE, board);
	return (0);
}

