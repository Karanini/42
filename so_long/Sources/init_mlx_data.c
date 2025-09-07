/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:36:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 17:26:26 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_delete_newlines(char **map);
/*

	* Creates the data structure and initializes each variable at 0 or NULL. It allows
 * to check in the further functions if the variables have been successfully
 * initialized or not.
 */
t_mlx_data	*ft_init_data_struct(void)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->mlx_connection = NULL;
	data->win = NULL;
	data->win_width = 0;
	data->win_height = 0;
	data->game_data = malloc(sizeof(t_game));
	if (!data->game_data)
		return (free(data), NULL);
	data->game_data->x = 0;
	data->game_data->y = 0;
	data->game_data->nb_moves = 0;
	data->game_data->nb_collectibles_left = 0;
	data->player = NULL;
	data->background = NULL;
	data->wall = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	return (data);
}

int	ft_init_mlx_data(t_mlx_data *data, char *win_title)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (-1);
	if (ft_check_screen_size(data) == -1)
		return (mlx_destroy_display(data->mlx_connection),
			free(data->mlx_connection), -1);
	data->win = mlx_new_window(data->mlx_connection, data->win_width,
			data->win_height, win_title);
	if (!data->win)
		return (mlx_destroy_display(data->mlx_connection),
			free(data->mlx_connection), -1);
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
	data->map_height = 0;
	tmp = NULL;
	res = NULL;
	while (line)
	{
		if (res)
			free(res);
		res = ft_strjoin(tmp, line, ' ');
		if (!res)
			return (free(tmp), free(line), close(fd), -1);
		if (tmp)
			free(tmp);
		tmp = ft_strdup(res);
		if (!tmp)
			return (free(line), free(res), close(fd), -1);
		free(line);
		line = get_next_line(fd);
		data->map_height++;
	}
	data->map = ft_split(res, ' ');
	if (!data->map)
		return (free(tmp), free(line), free(res), close(fd), -1);
	if (ft_delete_newlines(data->map) == -1)
		return (free_tab(data->map), free(tmp), free(line), free(res),
			close(fd), -1);
	return (free(tmp), free(line), free(res), close(fd), 0);
}

static int	ft_delete_newlines(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		tmp = ft_strtrim(map[i], "\n");
		if (!tmp)
			return (-1);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (0);
}

void	ft_init_player_pos(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->game_data->x = x;
				data->game_data->y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
