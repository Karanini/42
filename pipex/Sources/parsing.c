/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:07:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/05 11:37:37 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_files(char *argv[], int *fd_infile, int *fd_outfile)
{
	*fd_infile = open(argv[1], O_RDONLY);
	if (*fd_infile == -1)
		perror("pipex: infile");
	*fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (*fd_outfile == -1)
		perror("pipex: outfile");
	if (*fd_outfile == -1 || *fd_infile == -1)
		exit(EXIT_FAILURE);
}
