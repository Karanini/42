/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:02:45 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 15:22:00 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2_first_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head)
{
	if (fdes->fd_infile >= 0)
	{
		if (dup2(fdes->fd_infile, STDIN_FILENO) == -1)
			ft_cleanup_and_exit_child(fdes, head);
	}
	else
		ft_cleanup_and_exit_child(fdes, head);
	if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
		ft_cleanup_and_exit_child(fdes, head);
}

void	ft_dup2_last_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head)
{
	if (fdes->fd_outfile >= 0)
	{
		if (dup2(fdes->fd_outfile, STDOUT_FILENO) == -1)
			ft_cleanup_and_exit_child(fdes, head);
	}
	else
		ft_cleanup_and_exit_child(fdes, head);
	if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
		ft_cleanup_and_exit_child(fdes, head);
}
