/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:00:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 11:21:51 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_game	*ft_init_t_game_data()
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
