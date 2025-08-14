/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling_multipipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/14 17:06:26 by bkaras-g         ###   ########.fr       */
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
		printf("pid %d finished\n", cmd->pid);
		cmd = cmd->next;
	}
	ft_close_unused_fdes(fd_infile, fd_outfile, head);
	while (head)
	{
		printf("waiting for pid %d\n", head->pid);
		waitpid(head->pid, NULL, 0);
		printf("finished waiting\n");
		head = head->next;
	}
	return (0);
}

static void	ft_exec_child(int fd_infile, int fd_outfile, t_cmd *cmd,
		t_cmd *head)
{
	if (cmd->first)
	{
		printf("cmd %s is first\n", cmd->cmd);
		dup2(fd_infile, STDIN_FILENO); // protect the dup2 ?
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	else if (cmd->next == NULL)
	{
		printf("cmd %s is last\n", cmd->cmd);
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
	// printf("cmd->cmd : %s\n", cmd->cmd);
	// int i = 0;
	// while (cmd->argv[i])
	// 	{
	// 		ft_printf("   argv[%d] : %s   ", i, cmd->argv[i]);
	// 		i++;
	// 	}
	if (execve(cmd->cmd, cmd->argv, NULL) == -1)
	{
		if (errno == ENOENT)
			ft_putstr_fd("pipex: tunelling: command not found\n", 2);
		else
			perror("pipex: tunelling");
		ft_lstclear(&cmd);
		exit(127);
	}
	ft_lstclear(&head);
	exit(EXIT_SUCCESS);
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
	// ft_printf("fd_infile %d\n", fd_infile);
	// ft_printf("fd_outfile %d\n", fd_outfile);
	if ((fd_infile >= 0 && close(fd_infile) == -1) ||
		(fd_outfile >= 0 && close(fd_outfile) == -1))
		return (perror("pipex: close fd_files"), -1);
	while (cmd->next)
	{
		// ft_printf("cmd node %s\n", cmd->cmd);
		// ft_printf("pfd[0] : %d\n", cmd->pfd[0]);
		// ft_printf("pfd[1] : %d\n", cmd->pfd[1]);
		if ((cmd->pfd[0] >= 0 && close(cmd->pfd[0]) == -1) ||
			(cmd->pfd[1] >= 0 && close(cmd->pfd[1]) == -1))
			return (perror("pipex: close pfd"), -1);
		cmd = cmd->next;
	}
	return (0);
}
