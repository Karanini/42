/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/02 21:54:13 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	*data;
	char		*map[5] = {"11111",
						"1P0C1",
						"10001",
						"1C001",
						"11111"};

	data = malloc(sizeof(t_mlx_data)); // move the data init in another function
	// ft_init_mlx_data()
	if (!data)
		return (1);
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (1);
	data->win = mlx_new_window(data->mlx_connection, SIZE_X, SIZE_Y,
			"ARRI POTTAIRE");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		free(data);
		return (1);
	}
	if (ft_generate_images(data) == -1)
	{
		mlx_destroy_display(data->mlx_connection); // move to a cleanup function
		free(data->mlx_connection);
		free(data);
		return (1);
	}
	ft_generate_map(map, 5, 5, data);
	mlx_loop(data->mlx_connection);
}
