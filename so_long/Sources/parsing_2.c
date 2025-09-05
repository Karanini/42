/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:56:54 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 17:29:37 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_check_walls(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1'
			|| data->map[y][data->map_width - 1] != '1')
			return (-1);
		y++;
	}
	while (x < data->map_width)
	{
		if (data->map[0][x] != '1'
			|| data->map[data->map_height - 1][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}
