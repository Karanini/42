/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling_multipipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 15:21:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_exec_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head, char *env[]);
static void	ft_cmd_err_handling(t_cmd *cmd, t_cmd *head, t_fdes *fdes);
static int	ft_wait_children(t_cmd *head);

int	ft_create_pipes(t_cmd *cmd)
{
	int	nb_pipes;
	int	first;

	nb_pipes = ft_lstsize(cmd) - 1;
	first = 1;
	while (nb_pipes)
	{
		if (pipe(cmd->pfd) == -1)
			return (perror("pipex: ft_create_pipes"), -1);
		cmd->fd_out = cmd->pfd[1];
		cmd->next->fd_in = cmd->pfd[0];
		if (first-- == 1)
			cmd->first = 1;
		cmd = cmd->next;
		nb_pipes--;
	}
	return (0);
}

int	ft_fork(t_fdes *fdes, t_cmd *cmd, char *env[])
{
	t_cmd	*head;

	head = cmd;
	while (cmd)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (perror("pipex: ft_fork"), -1);
		if (cmd->pid == 0)
			ft_exec_child(fdes, cmd, head, env);
		cmd = cmd->next;
	}
	ft_close_unused_fdes(fdes, head);
	return (ft_wait_children(head));
}

static int	ft_wait_children(t_cmd *head)
{
	pid_t	pid;
	int		status;
	int		last_status;

	pid = 0;
	status = 0;
	last_status = 0;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == ft_lstlast(head)->pid)
			last_status = status;
	}
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(status));
	else
		return (0);
}

static void	ft_exec_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head, char *env[])
{
	if (!cmd->cmd_name)
		ft_cleanup_and_exit_child(fdes, head);
	if (cmd->first)
		ft_dup2_first_child(fdes, cmd, head);
	else if (cmd->next == NULL)
		ft_dup2_last_child(fdes, cmd, head);
	else
	{
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1 || dup2(cmd->fd_out,
				STDOUT_FILENO) == -1)
			ft_cleanup_and_exit_child(fdes, head);
	}
	if (ft_close_unused_fdes(fdes, head) == -1)
	{
		ft_lstclear(&head);
		free(fdes);
		exit(EXIT_FAILURE);
	}
	else
		execve(cmd->cmd_name, cmd->argv, env);
	ft_cmd_err_handling(cmd, head, fdes);
}

static void	ft_cmd_err_handling(t_cmd *cmd, t_cmd *head, t_fdes *fdes)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd->argv[0], 2);
	if (errno == EACCES)
	{
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		ft_lstclear(&head);
		free(fdes);
		exit(126);
	}
	else if (errno == ENOENT && ft_strchr(cmd->cmd_name, '/'))
		ft_putstr_fd(": no such file or directory", STDERR_FILENO);
	else if (errno == ENOENT)
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	else
		perror(NULL);
	ft_lstclear(&head);
	free(fdes);
	exit(127);
}
