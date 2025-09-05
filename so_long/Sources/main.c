/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 17:42:25 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
* malloc list : data structure, data->map to free with free_tab(),
* data->mlx_connection, display to free with mlx_destroy_display(),
* images to free with ft_destroy_images()
*/
int	main(int argc, char *argv[])
{
	t_mlx_data	*data;

	if (argc != 2)
		return (1);
	data = ft_init_data_struct();
	if (!data)
		return (1);
	if (ft_init_data_map(data, argv[1]) == -1)
		return (free(data->player_pos), free(data), 1);
	if (ft_check_map(data) == -1)
		return (free_tab(data->map), free(data->player_pos), free(data), 1);
	if (ft_init_mlx_data(data, "ARRI POTTAIRE") == -1)
		return (free_tab(data->map), free(data->player_pos), free(data), 1);
	if (ft_generate_images(data) == -1)
	{
		mlx_destroy_window(data->mlx_connection, data->win);
		mlx_destroy_display(data->mlx_connection); // move to a cleanup function
		free(data->mlx_connection);
		free_tab(data->map);
		free(data->player_pos);
		free(data);
		return (1);
	}
	ft_generate_map(data);
	ft_init_player_pos(data);
	ft_print_map(data);
	ft_print_player_pos(data->player_pos);
	mlx_key_hook(data->win, ft_handle_key, data);
	mlx_loop(data->mlx_connection);
}
