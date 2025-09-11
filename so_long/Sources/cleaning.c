/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:11:01 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 13:31:54 by bkaras-g         ###   ########.fr       */
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
/*
* to reduce lines: modify the char messages by int error codes ?
*/
int	ft_cleanup(t_mlx_data *data, int exit_code)
{
	if (exit_code == 0)
		ft_putendl_fd("Cleaning up and exiting...", 1);
	else if (exit_code == 1)
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
	free_tab(data->map);
	if (data->game_data)
		free(data->game_data);
	if (exit_code != 0)
		return (free(data), ft_putendl_fd("KTHXBYYYEEE", 2), exit_code);
	else
		return (free(data), ft_putendl_fd("KTHXBYYYEEE", 1), 0);
}

int	ft_exit_on_destroy(t_mlx_data *data)
{
	ft_cleanup(data, 0);
	exit(0);
}

void	ft_cleanup_imap(t_init_data_map *imap)
{
	int	GNL_exit_code;

	GNL_exit_code = 0;
	get_next_line(-1, &GNL_exit_code);
	if (imap->fd != -1)
		close(imap->fd);
	if (imap->line)
		free(imap->line);
	if (imap->tmp)
		free(imap->tmp);
	if (imap->res)
		free(imap->res);
	free(imap);
}
