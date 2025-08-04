/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:05:36 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/04 17:36:57 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int	fd_outfile;
	int	fd_infile;

	if (argc != 5)
		return (1);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		perror("pipex: infile");
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd_outfile == -1)
		perror("pipex: outfile");
	if (fd_outfile == -1 || fd_infile == -1)
		return (1);
	ft_tunelling(fd_infile, fd_outfile, argv);
	close(fd_outfile);
	close(fd_infile);
	return (0);
}

int	ft_tunelling(int fd_infile, int fd_outfile, char *argv[])
{
	dup2(fd_infile, STDIN_FILENO);
}


