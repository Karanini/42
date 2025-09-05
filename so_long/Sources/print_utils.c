/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:06:32 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 17:31:41 by bkaras-g         ###   ########.fr       */
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
		ft_printf("Map successfully initialized with values:\n");
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

void	ft_print_player_pos(t_player *player_pos)
{
	ft_printf("Player x position: %d\n", player_pos->x);
	ft_printf("Player y position: %d\n", player_pos->y);
}
