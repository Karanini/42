/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:11:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 16:02:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_mlx_data *data)
{
	if (data->mlx_connection)
	{
		if (data->player)
			mlx_destroy_image(data->mlx_connection, data->player);
		if (data->background)
			mlx_destroy_image(data->mlx_connection, data->background);
		if (data->wall)
			mlx_destroy_image(data->mlx_connection, data->wall);
		if (data->collectible)
			mlx_destroy_image(data->mlx_connection, data->collectible);
		if (data->exit)
			mlx_destroy_image(data->mlx_connection, data->exit);
	}
}

int	ft_cleanup(t_mlx_data *data, char *exit_reason)
{
	if (!ft_strcmp("ESC", exit_reason) || !ft_strcmp("DESTROY_WIN", exit_reason)
		|| !ft_strcmp("WRONG_MAP", exit_reason) || !ft_strcmp("SCREEN_SIZE",
			exit_reason))
		ft_putendl_fd("Cleaning up and exiting...", 1);
	else if (!ft_strcmp("END_GAME", exit_reason))
		ft_putendl_fd("You win!", 1);
	else if (!ft_strcmp("CRITICAL_ERR", exit_reason))
		ft_putendl_fd("Critical error! Cleaning up and exiting...", 2);
	if (data->mlx_connection)
	{
		if (data->win)
		{
			ft_destroy_images(data);
			mlx_destroy_window(data->mlx_connection, data->win);
		}
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
	}
	free_tab(data->map); // if !data->map already checked in free_tab()
	if (data->game_data)
		free(data->game_data);
	if (!ft_strcmp("CRITICAL_ERR", exit_reason))
		return (free(data), ft_putendl_fd("KTHXBYYYEEE", 2), 1);
	else
		return (free(data), ft_putendl_fd("KTHXBYYYEEE", 1), 0);
}

int	ft_exit_on_destroy(t_mlx_data *data)
{
	ft_cleanup(data, "DESTROY_WIN");
	exit(0);
}
