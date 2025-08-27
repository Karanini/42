/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:07:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/27 17:40:02 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Checks and processes input and output files from command-line arguments.
 *
 * This function analyzes the provided command-line arguments to determine
 * the input and output files required for the program's operation. It performs
 * necessary validation and returns a pointer to a structure containing file
 * descriptor information.
 *
 * Mandatory part (argc == 5) : if problem on both infile and outfile, the program
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
		ft_putstr_fd(": no such file or directory\n", 2);
	}
	fdes->fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fdes->fd_outfile == -1)
	{
		ft_putstr_fd(argv[argc - 1], 2);
		ft_putstr_fd(": permission denied\n", 2);
	}
	if (fdes->fd_outfile == -1 && fdes->fd_infile == -1 && argc == 5)
		return (free(fdes), NULL);
	return (fdes);
}

int	ft_check_path(t_cmd *cmd, char **env)
{
	char	**path_tab;
	char	*path;
	int		i;

	if (ft_strchr(cmd->cmd_name, '/') || !cmd->cmd_name)
		return (0);
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path_tab = ft_split(env[i] + 5, ':');
	if (!path_tab)
		return (-1);
	i = 0;
	while (path_tab[i])
	{
		path = ft_strjoin(path_tab[i++], cmd->cmd_name, '/');
		if (!path)
			return (free_tab(path_tab), -1);
		if (!access(path, X_OK))
			return (cmd->cmd_name = ft_strdup(path), free(path),
				free_tab(path_tab), 0);
		if (!access(path, F_OK))
			return (perror("parsing: "), free(path), free_tab(path_tab), -1);
		free(path);
	}
	return (free_tab(path_tab), 0);
}
