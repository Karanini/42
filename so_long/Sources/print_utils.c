/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:06:32 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/05 12:09:33 by bkaras-g         ###   ########.fr       */
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
		//print data->map initialized with values:
		while (data->map[i])
		{
			ft_printf("%s\n", data->map[i]);
			i++;
		}
	}
}
