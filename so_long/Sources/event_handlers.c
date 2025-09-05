/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:08:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 18:03:57 by bkaras-g         ###   ########.fr       */
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
		free_tab(data->map);
		free(data->player_pos);
		free(data);
		printf("KTHXBYYYEEE\n");
		exit(0);
	}
	// if (keycode == 119 | keycode == 97 || keycode == 115 || keycode == 100
	// 	|| keycode == 65361 || keycode == 65362 || keycode == 65363
	// 	|| keycode == 65364)
	// 	ft_move_player(keycode, data);
	if (keycode == 119 || keycode == 65362 || keycode == 115
		|| keycode == 65364)
		ft_move_player_y(keycode, data);
	if (keycode == 97 || keycode == 65361 || keycode == 100 || keycode == 65363)
		ft_move_player_x(keycode, data);
	return (0);
}

void	ft_move_player_y(int keycode, t_mlx_data *data)
{
	int	x;
	int	y;
	int	move_dir;

	x = data->player_pos->x;
	y = data->player_pos->y;
	if (keycode == 119 || keycode == 65362)
		move_dir = -1;
	else
		move_dir = 1;
	if (data->map[y + move_dir][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx_connection, data->win, data->player, x
		* 32, (y + move_dir) * 32);
	mlx_put_image_to_window(data->mlx_connection, data->win, data->background, x
		* 32, y * 32);
	data->player_pos->y += move_dir;
}

void	ft_move_player_x(int keycode, t_mlx_data *data)
{
	int	x;
	int	y;
	int	move_dir;

	x = data->player_pos->x;
	y = data->player_pos->y;
	if (keycode == 97 || keycode == 65361)
		move_dir = -1;
	else
		move_dir = 1;
	if (data->map[y][x + move_dir] == '1')
		return ;
	mlx_put_image_to_window(data->mlx_connection, data->win, data->player, (x
			+ move_dir) * 32, y * 32);
	mlx_put_image_to_window(data->mlx_connection, data->win, data->background, x
		* 32, y * 32);
	data->player_pos->x += move_dir;
}
