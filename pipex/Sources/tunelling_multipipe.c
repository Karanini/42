/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling_multipipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:16:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/27 17:51:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head, char *env[]);
// static int	ft_dup2_null(int new_fd);
static void	ft_cmd_err_handling(t_cmd *cmd, t_cmd *head, t_fdes *fdes);

int	ft_create_pipes(t_cmd *cmd)
{
	int	nb_pipes;
	int	first;

	nb_pipes = ft_lstsize(cmd) - 1;
	first = 1;
	while (nb_pipes)
	// or while (cmd->next->next) less lines but less readable
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
	int		status;
	int		last_status;
	pid_t	pid;

	pid = 0;
	status = 0;
	last_status = 0;
	head = cmd;
	while (cmd)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (perror("pipex: ft_fork"), -1);
		if (cmd->pid == 0)
			ft_exec_child(fdes, cmd, head, env);
		// fprintf(stderr, "pid %d finished\n", cmd->pid);
		cmd = cmd->next;
	}
	ft_close_unused_fdes(fdes, head);
	while (pid != -1)
	{
		// fprintf(stderr, "waiting for pid %d\n", head->pid);
		// waitpid(head->pid, NULL, 0);
		pid = wait(&status);
		if (pid == ft_lstlast(head)->pid)
			last_status = status;
		// fprintf(stderr, "finished waiting\n");
	}
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(status));
	else
		return (0);
}

static void	ft_exec_child(t_fdes *fdes, t_cmd *cmd, t_cmd *head, char *env[])
{
	// fprintf(stderr, "cmd name : %s\n", cmd->cmd_name);
	// fflush(stderr);
	if (!cmd->cmd_name)
	{
		// fprintf(stderr, "cmd not executed\n");
		// fflush(stderr);
		ft_cleanup_and_exit_child(fdes, head);
	}
	if (cmd->first)
	{
		if (fdes->fd_infile >= 0)
			dup2(fdes->fd_infile, STDIN_FILENO); // protect the dup2 ?
		else
		{
			ft_cleanup_and_exit_child(fdes, head);
			// ft_close_unused_fdes(fdes, head);
			// exit(EXIT_FAILURE);
			// if (ft_dup2_null(STDIN_FILENO) == -1)
			// 	exit(EXIT_FAILURE);
			// fprintf(stderr, "dup2 null successfully executed for %s\n", cmd->cmd_name);
		}
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	else if (cmd->next == NULL)
	{
		if (fdes->fd_outfile >= 0)
			dup2(fdes->fd_outfile, STDOUT_FILENO);
		else
		{
			ft_cleanup_and_exit_child(fdes, head);
			// ft_close_unused_fdes(fdes, head);
			// exit(EXIT_FAILURE);
			// if (ft_dup2_null(STDOUT_FILENO) == -1)
			// 	exit(EXIT_FAILURE);
		}
		dup2(cmd->fd_in, STDIN_FILENO);
		// fprintf(stderr, "dup2 successfully executed for %s\n", cmd->cmd_name);
		// fprintf(stderr, "cmd->fd_in : %d\n", cmd->fd_in);
	}
	else
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	if (ft_close_unused_fdes(fdes, head) == -1)
		exit(EXIT_FAILURE);
	// if ((cmd->first && fdes->fd_infile == -1) || (cmd->next == NULL
	// 		&& fdes->fd_outfile == -1))
	// {
	// 	// fprintf(stderr, "process %s not executed\n", cmd->cmd_name);
	// 	exit(EXIT_FAILURE);
	// }
	else
		execve(cmd->cmd_name, cmd->argv, env);
	ft_cmd_err_handling(cmd, head, fdes);
}

static void	ft_cmd_err_handling(t_cmd *cmd, t_cmd *head, t_fdes *fdes)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		ft_lstclear(&head);
		free(fdes);
		exit(127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		ft_lstclear(&head);
		free(fdes);
		exit(126);
	}
	else
	{
		perror("pipex: ft_exec_child");
		ft_lstclear(&head);
		free(fdes);
		exit(127);
	}
}

// static int	ft_dup2_null(int new_fd)
// {
// 	int	fd_null;

// 	fd_null = open("/dev/null", O_RDONLY);
// 	if (fd_null == -1)
// 		return (-1);
// 	fprintf(stderr, "fd_null : %d\n", fd_null);
// 	dup2(fd_null, new_fd);
// 	if (close(fd_null) == -1)
// 		return (-1);
// 	return (0);
// }
