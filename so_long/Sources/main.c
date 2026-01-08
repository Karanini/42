/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2026/01/08 15:20:50 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_hook_and_loop(t_mlx_data *data);

/*
 * malloc list : data structure, data->map to free with free_tab(),
 * data->mlx_connection, display to free with mlx_destroy_display(),
 * images to free with ft_destroy_images()
 *
 * Error codes:
 * -1 if a wrong map is detected (parsing error)
 * 1 if a critical error is detected (open() or malloc() fail)
 *
 * to do: spread love!! and nothing else
 */
int	main(int argc, char *argv[])
{
	t_mlx_data	*data;

	if (argc != 2)
		return (1);
	data = ft_init_t_mlx_data();
	if (!data)
		return (1);
	data->error_code = ft_init_data_map(data, argv[1]);
	if (data->error_code != 0)
		return (ft_cleanup(data, data->error_code));
	data->error_code = ft_check_map(data);
	if (data->error_code != 0)
		return (ft_cleanup(data, data->error_code));
	if (ft_init_mlx_ptr_and_win(data, "ARRI POTTAIRE") == 1
		|| ft_generate_images(data) == 1)
		return (ft_cleanup(data, 1));
	ft_generate_map(data);
	ft_hook_and_loop(data);
	return (0);
}

static void	ft_hook_and_loop(t_mlx_data *data)
{
	mlx_key_hook(data->win, ft_handle_key, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_exit_on_destroy,
		data);
	mlx_loop(data->mlx_connection);
}
