/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling_multipipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/14 15:14:19 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_child(int fd_infile, int fd_outfile, t_cmd *cmd,
				t_cmd *head);
static int	ft_close_unused_fdes(int fd_infile, int fd_outfile, t_cmd *cmd);

int	ft_create_pipes(t_cmd *cmd, int argc)
{
	int	nb_cmds;
	int	first;

	nb_cmds = argc - 3;
	first = 1;
	while (nb_cmds - 1)
	// or while (cmd->next->next) less lines but less readable
	{
		if (pipe(cmd->pfd) == -1)
			return (perror("pipex: ft_create_pipes"), -1);
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

int	ft_fork(int fd_infile, int fd_outfile, t_cmd *cmd)
{
	t_cmd	*head;

	head = cmd;
	while (cmd)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (perror("pipex: ft_fork_exec"), -1);
		if (cmd->pid == 0)
			ft_exec_child(fd_infile, fd_outfile, cmd, head);
		else
		{
			// ft_exec_parent(fd_infile, fd_outfile, head);
			ft_close_unused_fdes(fd_infile, fd_outfile, head);
			waitpid(cmd->pid, NULL, 0);
		}
		cmd = cmd->next;
	}
	ft_lstclear(&cmd);
	return (0);
}

static void	ft_exec_child(int fd_infile, int fd_outfile, t_cmd *cmd,
		t_cmd *head)
{
	if (cmd->first)
	{
		dup2(fd_infile, STDIN_FILENO); // protect the dup2 ?
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	else if (cmd->next == NULL)
	{
		dup2(fd_outfile, STDOUT_FILENO);
		dup2(cmd->fd_in, STDIN_FILENO);
	}
	else
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	if (ft_close_unused_fdes(fd_infile, fd_outfile, head) == -1)
		exit(EXIT_FAILURE);
	if (execve(cmd->cmd, cmd->argv, NULL) == -1)
	{
		if (errno == ENOENT)
			ft_putstr_fd("pipex: tunelling: command not found\n", 2);
		else
			perror("pipex: tunelling");
		ft_lstclear(&cmd);
		exit(127);
	}
}

// void	ft_exec_parent(int fd_infile, int fd_outfile, t_cmd *head)
// {
// 	ft_close_unused_fdes(fd_infile, fd_outfile, head);
// 	while (head)
// 	{
// 		waitpid(head->pid, NULL, 0);
// 		head = head->next;
// 	}
// }

static int	ft_close_unused_fdes(int fd_infile, int fd_outfile, t_cmd *cmd)
{
	if (close(fd_infile) || close(fd_outfile) == -1)
		return (perror("pipex: close"), -1);
	while (cmd->next->next)
	{
		if (close(cmd->pfd[0]) || close(cmd->pfd[1]) == -1)
			return (perror("pipex: close"), -1);
		cmd = cmd->next;
	}
	return (0);
}
