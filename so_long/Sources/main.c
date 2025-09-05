/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 12:05:36 by bkaras-g         ###   ########.fr       */
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
	int			win_width;
	int			win_height;
	char		*map[10] = {"1111111111",
						"1P000000C1",
						"10000C0001",
						"1C000000E1",
						"1000000001",
						"1000000001",
						"100C000001",
						"1000000001",
						"10000C0001",
						"1111111111"};

	if (argc != 2)
		return (1);
	data = ft_init_data_struct();
	if (!data)
		return (1);
	if (ft_init_data_map(data, argv[1]) == -1)
		return (free(data), 1);
	for (int i = 0; data->map[i] != NULL; i++)
	{
		ft_printf("%s\n", data->map[i]);
	}
	if (ft_check_map(data) == -1)
		return (free_tab(data->map), free(data), 1);
	win_width = 10 * 32;
	win_height = 10 * 32; // to generalize in ft_init_data_map() : y_size * 32

	if (ft_init_mlx_data(data, "ARRI POTTAIRE", win_width, win_height) == -1)
		return (1); //free everything that has been malloced
	data->player_pos->x = 2;
	data->player_pos->y = 2;

	if (!data)
		return (1);
	if (ft_generate_images(data) == -1)
	{
		mlx_destroy_display(data->mlx_connection); // move to a cleanup function
		free(data->mlx_connection);
		free(data);
		return (1);
	}
	ft_generate_map(map, 10, 10, data); //update with data->map
	mlx_key_hook(data->win, ft_handle_key, data);
	mlx_loop(data->mlx_connection);
}
