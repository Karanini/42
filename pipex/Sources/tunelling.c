/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:05:36 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/04 13:18:31 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int	fd_outfile;

	if (argc != 5)
		return (1);
	fd_outfile = ft_check_outfile(argv[4]);
	ft_printf("fd outfile : %d\n", fd_outfile);
	if (!fd_outfile)
		return (1);
	if (ft_check_infile(argv[1]))
		return (0);
		//ft_tunelling(argv);
		// passer a la suite du tunneling
	else
		return (1);
	close(fd_outfile);
	return (0);
}

int	ft_check_infile(char* filename)
{
	if (!access(filename, R_OK))
	{
		ft_printf("Le fichier existe et est readable\n");
		return (1);
	}
	else if (!access(filename, F_OK)) //file exists but not readable
		ft_printf("permission denied: %s\n", filename);
	else //file doesn't exist
		ft_printf("no such file or directory: %s\n", filename);
	return (0);
}
/*
* checks if outfile exists and is writable. Optimisation possibility :
* open() returns -1 when file exists and is not writable
*/
int	ft_check_outfile(char *filename)
{
	if (!access(filename, F_OK) && access(filename, W_OK))
	{
		ft_printf("permission denied: %s\n", filename);
		return (0);
	}
	return (open(filename, O_WRONLY | O_CREAT | O_TRUNC, 777));
}
