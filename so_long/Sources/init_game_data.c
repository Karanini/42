/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:00:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:44 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_delete_newlines(char **map);

t_game	*ft_init_t_game_data(void)
{
	t_game	*game_data;

	game_data = malloc(sizeof(t_game));
	if (!game_data)
		return (NULL);
	game_data->player_x = 0;
	game_data->player_y = 0;
	game_data->exit_x = 0;
	game_data->exit_y = 0;
	game_data->nb_moves = 0;
	game_data->nb_collectibles_left = 0;
	return (game_data);
}

/**
 * @brief Initializes the game data map from the specified file.
 *
 * This function loads and initializes the map data for the game using the
 * provided filename. It sets up the necessary structures in the t_mlx_data
 * object to represent the game map.
 *
 * @param data Pointer to the t_mlx_data structure.
 * @param filename Path to the file containing the map data.
 * @return int Returns 0 on success, or -1 if a malloc fails.
 */
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
	// ft_print_map(data);
	if (!data->map)
		return (free(tmp), free(line), free(res), close(fd), -1);
	if (ft_delete_newlines(data->map) == -1)
		return (free(tmp), free(line), free(res), close(fd), -1);
	return (free(tmp), free(line), free(res), close(fd), 0);
}

static int	ft_delete_newlines(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		// ft_printf("line %p:\n%s", map[i], map[i]);
		tmp = ft_strtrim(map[i], "\n");
		if (!tmp)
			return (-1);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (0);
}

void	ft_init_player_and_exit_pos(t_mlx_data *data)
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
				data->game_data->player_x = x;
				data->game_data->player_y = y;
			}
			else if (data->map[y][x] == 'E')
			{
				data->game_data->exit_x = x;
				data->game_data->exit_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
