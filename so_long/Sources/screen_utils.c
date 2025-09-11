/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:43:28 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 16:32:11 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_screen_size(t_mlx_data *data)
{
	int		screen_width;
	int		screen_height;
	int		tab[2];
	char	*err_msg;

	err_msg = "You're dreaming too big my friend please reduce the map size";
	screen_height = 0;
	screen_width = 0;
	tab[0] = screen_height;
	tab[1] = screen_width;
	mlx_get_screen_size(data->mlx_connection, &tab[1], &tab[0]);
	data->win_height = data->map_height * 32;
	data->win_width = data->map_width * 32;
	if (data->win_height > tab[0] || data->win_width > tab[1])
		return (ft_print_err(err_msg), -1);
	return (0);
}
