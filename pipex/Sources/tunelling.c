/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunelling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:05:36 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 18:32:54 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_child(int fd_infile, int fd_outfile, t_cmd *head,
				int pipe_fd[2]);
static void	ft_exec_parent(int fd_infile, int fd_outfile, t_cmd *head,
		int pipe_fd[2]);

int	ft_tunelling(int fd_infile, int fd_outfile, t_cmd *head)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (perror("pipex: tunelling"), -1);
	head->pid = fork();
	if (head->pid == -1)
		return (perror("pipex: tunelling"), -1);
	if (head->pid == 0)
		ft_exec_child(fd_infile, fd_outfile, head, pipe_fd);
	else
		ft_exec_parent(fd_infile, fd_outfile, head, pipe_fd);
	return (1);
}

static void	ft_exec_child(int fd_infile, int fd_outfile, t_cmd *head,
		int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(fd_outfile);
	if (dup2(fd_infile, STDIN_FILENO) == -1 || dup2(pipe_fd[1],
			STDOUT_FILENO) == -1)
	{
		perror("pipex: tunelling");
		ft_lstclear(&head);
		exit(EXIT_FAILURE); // exit closes the file descriptors so
							// normally no need to handle them
	}
	close(fd_infile);
	close(pipe_fd[1]);
	if (execve(head->cmd, head->argv, NULL) == -1)
	{
		if (errno == ENOENT)
			ft_putstr_fd("pipex: tunelling: command not found\n", 2);
		else
			perror("pipex: tunelling");
		ft_lstclear(&head);
		exit(127);
	}
	ft_lstclear(&head);
	exit(EXIT_SUCCESS);
}

static void	ft_exec_parent(int fd_infile, int fd_outfile, t_cmd *head,
		int pipe_fd[2])
{
	close(pipe_fd[1]);
	close(fd_infile);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(fd_outfile,
			STDOUT_FILENO) == -1)
	{
		perror("pipex: tunelling");
		ft_lstclear(&head);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(fd_outfile);
	waitpid(head->pid, NULL, 0);
	if (execve(head->next->cmd, head->next->argv, NULL) == -1)
	{
		if (errno == ENOENT)
			ft_putstr_fd("pipex: tunelling: command not found\n", 2);
		else
			perror("pipex: tunelling");
		ft_lstclear(&head);
		exit(127);
	}
	// it seems like code is not read anymore after execve()
	ft_putstr_fd("on arrive la ?\n", 2);
	ft_lstclear(&head);
	exit(EXIT_SUCCESS);
}
