/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:07:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 13:09:10 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_check_paths_access(char *path_tab[], t_cmd *cmd);

/**

* @brief Checks and processes input and output files from command-line arguments.
 *
 * This function analyzes the provided command-line arguments to determine
 * the input and output files required for the program's operation. It performs
 * necessary validation and returns a pointer to a structure containing file
 * descriptor information.
 *
 * Mandatory part (argc == 5) : if problem on both infile and outfile,
	the program
 * exits after printing both error messages (and returning exit code 1
 * in the main function).
 *
 * @param argv Array of command-line argument strings.
 * @param argc Number of command-line arguments.
 * @return Pointer to a t_fdes structure containing file descriptor information,
 *         or NULL if an error occurs.
 */
t_fdes	*ft_check_files(char *argv[], int argc)
{
	t_fdes	*fdes;

	fdes = malloc(sizeof(t_fdes));
	if (!fdes)
		return (NULL);
	fdes->fd_infile = open(argv[1], O_RDONLY);
	if (fdes->fd_infile == -1)
	{
		ft_putstr_fd(argv[1], 2);
		if (access(argv[1], F_OK) == 0 && access(argv[1], R_OK) == -1)
			ft_putstr_fd(": Permission denied", 2);
		else
			ft_putstr_fd(": No such file or directory\n", 2);
	}
	fdes->fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fdes->fd_outfile == -1)
	{
		ft_putstr_fd(argv[argc - 1], 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (fdes->fd_outfile == -1 && fdes->fd_infile == -1 && argc == 5)
		return (free(fdes), NULL);
	return (fdes);
}

/**
 * Checks and sets the executable path for the given command structure
 * with $PATH. For example 'ls' becomes '/usr/bin/ls'
 *
 * If env is empty (!env[0]) nothing to be done -> the function stops.
 * If a cmd_name contains at leat one '/' a path is already given so
 * no path is set with $PATH.
 *
 * @param cmd Pointer to the t_cmd structure containing command information.
 * @param env Array of environment variable strings.
 * @return 0 if nothing to be done or if one or several valid paths are
 * found and set, -1 if a malloc error is found.
 */
int	ft_check_path(t_cmd *cmd, char **env)
{
	char	**path_tab;
	int		i;

	if (!env[0])
		return (0);
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (0);
	path_tab = ft_split(env[i] + 5, ':');
	if (!path_tab)
		return (-1);
	while (cmd)
	{
		if (!ft_strchr(cmd->cmd_name, '/') && cmd->cmd_name)
		{
			if (ft_check_paths_access(path_tab, cmd) == -1)
				return (free_tab(path_tab), -1);
		}
		cmd = cmd->next;
	}
	return (free_tab(path_tab), 0);
}

/**
 * @brief Checks the accessibility of the given paths for the specified command.
 *
 * This function iterates through the array of paths (`path_tab`) and determines
 * if any of the paths provide access to the executable specified in `cmd`.
 *
 * @param path_tab An array of strings representing possible executable paths.
 * @param cmd Pointer to a t_cmd structure containing command information.
 * @return int Returns -1 on a malloc error, 0 otherwise (whether an accessible
 * path is found or not).
 */
static int	ft_check_paths_access(char *path_tab[], t_cmd *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (path_tab[i])
	{
		path = ft_strjoin(path_tab[i++], cmd->cmd_name, '/');
		if (!path)
			return (perror("parsing: "), -1);
		if (!access(path, X_OK))
		{
			cmd->cmd_name = ft_strdup(path);
			if (!cmd->cmd_name)
				return (perror("parsing: "), free(path), -1);
			else
				return (free(path), 0);
		}
		free(path);
	}
	return (0);
}
