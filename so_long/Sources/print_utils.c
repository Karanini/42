/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:06:32 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 16:18:40 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_err(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
}

void	ft_print_map(t_mlx_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			ft_printf("%s\n", data->map[i]);
			i++;
		}
	}
	else
		ft_print_err("The map has not been initialized.\n");
	ft_printf("\n");
	ft_printf("map width: %d\n", data->map_width);
	ft_printf("map height: %d\n", data->map_height);
}

void	ft_print_player_pos(t_game *game_data)
{
	ft_printf("Player x position: %d\n", game_data->player_x);
	ft_printf("Player y position: %d\n", game_data->player_y);
}

void	ft_print_err_items(int count, char to_check)
{
	if (!count)
	{
		if (to_check == 'E')
			ft_print_err("No exit no game byeeee");
		else if (to_check == 'P')
			ft_print_err("No player no game byeeee");
		else if (to_check == 'C')
			ft_print_err("No collectibles no game byeeee");
	}
	if (count > 1)
	{
		if (to_check == 'E')
			ft_print_err("Too many exits!");
		if (to_check == 'P')
			ft_print_err("Too many players!");
	}
}
