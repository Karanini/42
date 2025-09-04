/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:08:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/04 10:20:33 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int keycode, t_mlx_data *data)
{
	printf("You pressed the key %d\n", keycode);
	if (keycode == XK_Escape)
	{
		printf("ESC key pressed. Cleaning up and exiting program...\n");
		ft_destroy_images(data);
		mlx_destroy_window(data->mlx_connection, data->win);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		free(data);
		printf("KTHXBYYYEEE\n");
		exit(0);
	}
	// if (keycode == 119 | keycode == 97 || keycode == 115 || keycode == 100
	// 	|| keycode == 65361 || keycode == 65362 || keycode == 65363
	// 	|| keycode == 65364)
	// 	ft_move_player(keycode, data);
	return (0);
}
