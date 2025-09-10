/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:36:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 15:47:11 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

* Creates the data structure and initializes each variable at 0 or NULL.
* It allows to check in the further functions if the variables have been
* successfully initialized or not.
 */
t_mlx_data	*ft_init_t_mlx_data(void)
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
	data->game_data = ft_init_t_game_data();
	if (!data->game_data)
		return (free(data), NULL);
	data->player = NULL;
	data->background = NULL;
	data->wall = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	data->error_code = 0;
	return (data);
}

/**
 * @brief Initializes the MLX pointer and creates a new window.
 *
 * This function sets up the MLX context and opens a new window with
 * the specified title. It stores the necessary pointers in the provided
 * t_mlx_data structure.
 *
 * Before opening a new window, ft_check_screen_size() is called to check
 * if the map provided is too big for the screen where it should be displayed.
 * If the map is too big, ft_cleanup() is called to free all the mallocs
 * and to exit the program.
 *
 * @param data Pointer to a t_mlx_data structure where MLX pointers will be stored.
 * @param win_title The title to be used for the new window.
 * @return 0 on success, or -1 if a malloc fails.
 */
int	ft_init_mlx_ptr_and_win(t_mlx_data *data, char *win_title)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (-1);
	if (ft_check_screen_size(data) == -1)
	{
		ft_cleanup(data, "SCREEN_SIZE");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx_connection, data->win_width,
			data->win_height, win_title);
	if (!data->win)
		return (-1);
	return (0);
}
