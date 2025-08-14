/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling_multipipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/14 13:32:32 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_create_pipes(int fd_infile, int fd_outfile, t_cmd *cmd, int argc)
{
	int	nb_cmds;
	int	first;

	nb_cmds = argc - 3;
	first = 1;
	while (nb_cmds - 1) // or while (cmd->next->next) less lines but less readable
	{
		if (pipe(cmd->pfd) == -1)
			return (perror("pipex: tunelling"), -1);
		cmd->fd_out = cmd->pfd[1];
		cmd->next->fd_in = cmd->pfd[0];
		if (first)
			cmd->first = 1;
		first = 0;
		cmd = cmd->next;
		nb_cmds--;
	}
	return (0);
}


