/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:36:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/03 19:30:41 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_mlx_data(t_mlx_data *data, char *win_title, int win_width,
		int win_height)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (free(data), -1);
	data->win = mlx_new_window(data->mlx_connection, win_width, win_height,
			win_title);
	if (!data->win)
		return (mlx_destroy_display(data->mlx_connection),
			free(data->mlx_connection), free(data), -1);
	data->player = NULL;
	data->background = NULL;
	data->wall = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	return (0);
}

int	ft_init_data_map(t_mlx_data *data, char *filename)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;

	fd = open(filename, O_RDONLY); // other flags to put ?
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	data->map_height++;
	while (line)
	{
		tmp = ft_strdup(line);
		if (!tmp)
			return (free(line), -1);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (free(tmp), -1);
				// on entre ici si on arrive a la fin du fichier ?
		res = ft_strjoin(tmp, line, ' ');
		if (!res)
			return (free(tmp), free(line), -1);
		free(tmp);
		data->map_height++;
	}
	data->map = ft_split(res, ' ');
	if (!data->map)
}
