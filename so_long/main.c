/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/03 15:54:01 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
* malloc list : data structure, data->mlx_connection, display to free with
* mlx_destroy_display(), images to free with ft_destroy_images()
*/
int	main(void)
{
	t_mlx_data	*data;
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

	data = ft_init_mlx_data("ARRI POTTAIRE");
	if (!data)
		return (1);
	if (ft_generate_images(data) == -1)
	{
		mlx_destroy_display(data->mlx_connection); // move to a cleanup function
		free(data->mlx_connection);
		free(data);
		return (1);
	}
	ft_generate_map(map, 10, 10, data);
	mlx_loop(data->mlx_connection);
}
