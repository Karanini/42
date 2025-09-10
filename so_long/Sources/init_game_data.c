/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:00:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/09 17:42:40 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int				ft_delete_newlines(char **map);
static t_init_data_map	*ft_init_struct(t_mlx_data *data, char *filename);

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
	t_init_data_map	*imap;

	imap = ft_init_struct(data, filename);
	if (!imap)
		return (data->error_code);
	while (imap->line)
	{
		if (imap->res)
			free(imap->res);
		imap->res = ft_strjoin(imap->tmp, imap->line, ' ');
		if (!imap->res)
			return (ft_cleanup_imap(imap), 1);
		if (imap->tmp)
			free(imap->tmp);
		imap->tmp = ft_strdup(imap->res);
		if (!imap->tmp)
			return (ft_cleanup_imap(imap), 1);
		free(imap->line);
		imap->line = get_next_line(imap->fd);
		data->map_height++;
	}
	data->map = ft_split(imap->res, ' ');
	if (!data->map)
		return (ft_cleanup_imap(imap), 1);
	return (ft_cleanup_imap(imap), ft_delete_newlines(data->map));
}

static t_init_data_map	*ft_init_struct(t_mlx_data *data, char *filename)
{
	t_init_data_map	*imap;

	imap = malloc(sizeof(t_init_data_map));
	if (!imap)
		return (data->error_code = 1, NULL);
	imap->tmp = NULL;
	imap->res = NULL;
	imap->fd = open(filename, O_RDONLY); // other flags to put ?
	if (imap->fd == -1)
		return (data->error_code = 1, free(imap), NULL);
	imap->line = get_next_line(imap->fd);
	if (!imap->line)
		return (data->error_code = -1,
			ft_print_err("Empty file! No map no game byyee"),
			ft_cleanup_imap(imap), NULL);
	data->map_height = 0;
	return (imap);
}

static int	ft_delete_newlines(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		if (!ft_strcmp(map[i], "\n") || !ft_strcmp(map[i], "\r\n"))
			return (ft_print_err("Empty line detected."), -1);
		// ft_printf("line %p:\n%s", map[i], map[i]);
		tmp = ft_strtrim(map[i], "\n\r");
		if (!tmp)
			return (1);
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
