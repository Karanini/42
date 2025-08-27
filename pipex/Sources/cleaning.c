/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/27 17:14:17 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
* @brief frees all the nodes of a t_cmd list with 2 steps : (1) Frees the
* allocated variables in a node, (2) then frees the node.
*
* If the cmd_name variable has been updated with the absolute path with ft_check_path,
* we free also cmd_name. If not, it's enough to free argv since argv[0] == cmd_name.
*/
void	ft_lstclear(t_cmd **lst)
{
	t_cmd	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if ( (*lst)->argv[0] && (*lst)->cmd_name
			&& ft_strcmp((*lst)->argv[0], (*lst)->cmd_name))
			free((*lst)->cmd_name);
		free_tab((*lst)->argv);
		free(*lst);
		*lst = temp;
	}
}

int	ft_close_unused_fdes(t_fdes *fdes, t_cmd *cmd)
{
	// ft_printf("fd_infile %d\n", fd_infile);
	// ft_printf("fd_outfile %d\n", fd_outfile);
	if ((fdes->fd_infile >= 0 && close(fdes->fd_infile) == -1)
		|| (fdes->fd_outfile >= 0 && close(fdes->fd_outfile) == -1))
		return (perror("pipex: close fd_files"), -1);
	while (cmd)
	{
		// ft_printf("cmd node %s\n", cmd->cmd_name);
		// ft_printf("pfd[0] : %d\n", cmd->pfd[0]);
		// ft_printf("pfd[1] : %d\n", cmd->pfd[1]);
		if ((cmd->pfd[0] >= 0 && close(cmd->pfd[0]) == -1) || (cmd->pfd[1] >= 0
				&& close(cmd->pfd[1]) == -1))
			return (perror("pipex: close pfd"), -1);
		cmd = cmd->next;
	}
	return (0);
}

void	ft_cleanup_and_exit_child(t_fdes *fdes, t_cmd *head)
{
	ft_close_unused_fdes(fdes, head);
	ft_lstclear(&head);
	free(fdes);
	exit(EXIT_FAILURE);
}
