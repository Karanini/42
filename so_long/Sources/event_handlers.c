/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:08:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 11:14:58 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_increment_and_print_nb_moves(t_game *player);
static void	ft_grab_collectible(t_mlx_data *data);

int	ft_handle_key(int keycode, t_mlx_data *data)
{
	int	put_exit_img;

	put_exit_img = 0;
	if (keycode == XK_Escape)
		exit(ft_cleanup(data, 0));
	if (keycode == 119 || keycode == 65362 || keycode == 115
		|| keycode == 65364)
		ft_move_player_y(keycode, data);
	if (keycode == 97 || keycode == 65361 || keycode == 100 || keycode == 65363)
		ft_move_player_x(keycode, data);
	if (data->game_data->nb_collectibles_left == 0)
	{
		if (!put_exit_img)
		{
			mlx_put_image_to_window(data->mlx_connection, data->win, data->exit,
				data->game_data->exit_x * 32, data->game_data->exit_y * 32);
			put_exit_img++;
		}
		if (data->game_data->exit_x == data->game_data->player_x
			&& data->game_data->exit_y == data->game_data->player_y)
		{
			ft_putendl_fd("You win!", 1);
			exit(ft_cleanup(data, 0));
		}
	}
	return (0);
}

void	ft_move_player_y(int keycode, t_mlx_data *data)
{
	int	x;
	int	y;
	int	move_dir;

	x = data->game_data->player_x;
	y = data->game_data->player_y;
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
	data->game_data->player_y += move_dir;
	if (data->map[y + move_dir][x] == 'C')
		ft_grab_collectible(data);
	ft_increment_and_print_nb_moves(data->game_data);
}

void	ft_move_player_x(int keycode, t_mlx_data *data)
{
	int	x;
	int	y;
	int	move_dir;

	x = data->game_data->player_x;
	y = data->game_data->player_y;
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
	data->game_data->player_x += move_dir;
	if (data->map[y][x + move_dir] == 'C')
		ft_grab_collectible(data);
	ft_increment_and_print_nb_moves(data->game_data);
}

static void	ft_increment_and_print_nb_moves(t_game *player)
{
	player->nb_moves++;
	if (player->nb_moves == 1)
		ft_printf("Player moved %d time\n", player->nb_moves);
	else
		ft_printf("Player moved %d times\n", player->nb_moves);
}

static void	ft_grab_collectible(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->game_data->player_x;
	y = data->game_data->player_y;
	data->map[y][x] = '0';
	data->game_data->nb_collectibles_left--;
	if (data->game_data->nb_collectibles_left != 0)
		ft_printf("Collectible grabbed! You have %d left.\n",
			data->game_data->nb_collectibles_left);
	else
		ft_putendl_fd("You grabbed all the collectibles! Go to the exit", 1);
}
