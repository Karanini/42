/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:11:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/03 15:53:27 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_mlx_data *data)
{
	//add if (data->player) etc
	mlx_destroy_image(data->mlx_connection, data->player);
	mlx_destroy_image(data->mlx_connection, data->background);
	mlx_destroy_image(data->mlx_connection, data->wall);
	mlx_destroy_image(data->mlx_connection, data->collectible);
	mlx_destroy_image(data->mlx_connection, data->exit);
}
