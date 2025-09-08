/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:19:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/08 16:11:40 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * malloc list : data structure, data->map to free with free_tab(),
 * data->mlx_connection, display to free with mlx_destroy_display(),
 * images to free with ft_destroy_images()
 */
int	main(int argc, char *argv[])
{
	t_mlx_data	*data;
	int			ft_check_map_ret;

	if (argc != 2)
		return (1);
	data = ft_init_t_mlx_data();
	if (!data)
		return (1);
	if (ft_init_data_map(data, argv[1]) == -1)
		return (ft_cleanup(data, "CRITICAL_ERR"));
	ft_check_map_ret = ft_check_map(data);
	if (ft_check_map_ret == -1)
		return (ft_cleanup(data, "WRONG_MAP"));
	else if (ft_check_map_ret == 1)
		return (ft_cleanup(data, "CRITICAL_ERR"));
	if (ft_init_mlx_ptr_and_win(data, "ARRI POTTAIRE") == -1
		|| ft_generate_images(data) == -1)
		return (ft_cleanup(data, "CRITICAL_ERR"));
	ft_generate_map(data);
	ft_init_player_and_exit_pos(data);
	mlx_key_hook(data->win, ft_handle_key, data);
	// mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_exit_on_destroy, data);
	mlx_loop(data->mlx_connection);
	return (0);
}
