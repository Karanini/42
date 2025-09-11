/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:00:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 16:27:02 by bkaras-g         ###   ########.fr       */
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
		imap->line = get_next_line(imap->fd, &data->error_code);
		data->map_height++;
	}
	data->map = ft_split(imap->res, ' ');
	if (!data->map || data->error_code == 1)
		return (ft_cleanup_imap(imap), 1);
	return (ft_cleanup_imap(imap), ft_delete_newlines(data->map));
}

/**
 * @brief Initializes and allocates a t_init_data_map structure using the
 *        provided MLX data and map filename.
 *
 * @param data      Pointer to the MLX data structure used for graphical
 * context.
 * @param filename  Path to the map file to be loaded and initialized.
 * @return Pointer to the newly allocated and initialized t_init_data_map
 *         structure, or NULL if initialization fails or if an empty file
 * is detected.
 */
static t_init_data_map	*ft_init_struct(t_mlx_data *data, char *filename)
{
	t_init_data_map	*imap;
	int				gnl_exit_code;

	imap = malloc(sizeof(t_init_data_map));
	gnl_exit_code = 0;
	if (!imap)
		return (data->error_code = 1, NULL);
	imap->tmp = NULL;
	imap->res = NULL;
	imap->fd = open(filename, O_RDONLY);
	if (imap->fd == -1)
		return (data->error_code = 1, free(imap), NULL);
	imap->line = get_next_line(imap->fd, &gnl_exit_code);
	if (!imap->line)
		return (data->error_code = -1,
			ft_print_err("Empty file! No map no game byyee"),
			ft_cleanup_imap(imap), NULL);
	data->map_height = 0;
	return (imap);
}

/**
 * @brief Removes newline characters at the end of each string in the
 * given map array.
 *
 * This function iterates over the array of strings pointed to by `map`
 * and deletes any newline characters `\\n` found at the end of each
 * string. If an empty line is detected the function stops and throws
 * an error.
 *
 * @param map A NULL-terminated array of strings representing the map.
 * @return int Returns 0 on success, or a non-zero value if an error
 * occurs.
 */
static int	ft_delete_newlines(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		if (!ft_strcmp(map[i], "\n") || !ft_strcmp(map[i], "\r\n"))
			return (ft_print_err("Empty line detected."), -1);
		tmp = ft_strtrim(map[i], "\n\r");
		if (!tmp)
			return (1);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (0);
}

/**
 * @brief Initializes the player's and exit's positions in the game data.
 *
 * This function sets up the initial coordinates for the player and the exit
 * within the provided t_mlx_data structure. It should be called during the
 * game initialization phase to ensure that both the player and exit are
 * correctly placed on the game map.
 *
 * @param data Pointer to the t_mlx_data structure containing game state
 * information.
 */
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
