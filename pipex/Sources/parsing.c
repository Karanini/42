/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:07:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 15:07:56 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_files(char *argv[], int *fd_infile, int *fd_outfile)
{
	*fd_infile = open(argv[1], O_RDONLY);
	if (*fd_infile == -1)
		perror("pipex: infile");
	*fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (*fd_outfile == -1)
		perror("pipex: outfile");
	if (*fd_outfile == -1 || *fd_infile == -1)
		exit(EXIT_FAILURE);
}

int	ft_check_path(char **cmd, char **env)
{
	char	**path_tab;
	char	*path;
	int		i;

	if (ft_strchr(*cmd, '/'))
		return (0);
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
	{
		ft_printf("env[%d] : %s\n", i, env[i]);
		i++;
	}
	path_tab = ft_split(env[i] + 5, ':');
	if (!path_tab)
		return (-1);
	i = 0;
	while (path_tab[i])
	{
		path = ft_strjoin(path_tab[i++], *cmd, '/');
		ft_printf("path : %s\n", path);
		if (!path)
			return (free_tab(path_tab), -1);
		if (!access(path, X_OK))
			return (*cmd = ft_strdup(path), free(path),
				free_tab(path_tab), 1);
		if (!access(path, F_OK))
			return (perror("parsing: "), free(path), free_tab(path_tab), -1);
		free(path);
	}
	return (free_tab(path_tab), 0);
}
