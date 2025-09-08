/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:39:02 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 11:41:41 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*ft_convert_xpm_to_images(void *mlx_connection, char *path);

int	ft_generate_images(t_mlx_data *data)
{
	data->player = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/player1.xpm");
	if (!data->player)
		return (-1);
	data->background = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/background.xpm");
	if (!data->background)
		return (ft_destroy_images(data), -1);
	data->wall = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/wall.xpm");
	if (!data->wall)
		return (ft_destroy_images(data), -1);
	data->collectible = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/collectible1.xpm");
	if (!data->collectible)
		return (ft_destroy_images(data), -1);
	data->exit = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/exit.xpm");
	if (!data->exit)
		return (ft_destroy_images(data), -1);
	return (0);
}

static t_img	*ft_convert_xpm_to_images(void *mlx_connection, char *path)
{
	t_img	*player;
	int		width;
	int		height;

	width = 30;
	height = 31;
	player = mlx_xpm_file_to_image(mlx_connection, path, &width, &height);
	if (!player)
		return (NULL);
	return (player);
}

void	ft_generate_map(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
	{
		while (y < data->map_height)
		{
			if (data->map[y][x] == '0' || data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_connection, data->win,
					data->background, x * 32, y * 32);
			else if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_connection, data->win,
					data->wall, x * 32, y * 32);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_connection, data->win,
					data->player, x * 32, y * 32);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_connection, data->win,
					data->collectible, x * 32, y * 32);
			// else if (data->map[y][x] == 'E')
			// 	mlx_put_image_to_window(data->mlx_connection, data->win,
			// 		data->exit, x * 32, y * 32);
			y++;
		}
		y = 0;
		x++;
	}
}
