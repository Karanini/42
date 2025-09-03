/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:36:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/03 15:46:50 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx_data	*ft_init_mlx_data(char *win_title)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (free(data), NULL);
	data->win = mlx_new_window(data->mlx_connection, SIZE_X, SIZE_Y, win_title);
	if (!data->win)
		return (mlx_destroy_display(data->mlx_connection),
			free(data->mlx_connection), free(data), NULL);
	data->player = NULL;
	data->background = NULL;
	data->wall = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	return (data);
}
