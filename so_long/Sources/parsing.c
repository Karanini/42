/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:53:25 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/04 17:57:12 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_EPC(t_mlx_data *data, char to_check);

int	ft_check_map(t_mlx_data *data)
{
	if (ft_check_EPC(data, 'E') == -1 || ft_check_EPC(data, 'P') == -1
		|| ft_check_EPC(data, 'C') == -1)
		return (-1);
	//check init width
	return (0);
}
/*
* Checks for the Exit Player and Collectible requirements.

* To optimize norm : handle error printing completely apart ? Sending
* to_check and count to this other function.
*/
static int	ft_check_EPC(t_mlx_data *data, char to_check)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			// ft_printf("%c", data->map[y][x]);
			if (data->map[y][x] == to_check)
			{
				count++;
				if (to_check == 'E' && count > 1)
					return (ft_print_err("Too many exits!"), -1);
				if (to_check == 'P' && count > 1)
					return (ft_print_err("Too many players!"), -1);
			}
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
	if (!count && to_check == 'E')
		return (ft_print_err("No exit no game byeeee"), -1);
	else if (!count && to_check == 'P')
		return (ft_print_err("No player no game byeeee"), -1);
	else if (!count && to_check == 'C')
		return (ft_print_err("No collectibles no game byeeee"), -1);
	return (0);
}

int	ft_check_init_width(t_mlx_data *data)
{
	int	i;
	int	j;
	int	*tab_width;

	tab_width = malloc(sizeof(int) * data->map_height);
	if (!tab_width)
		return (perror("tab_width malloc failed"), 1);
			// catch the 1 return to free the rest and exit
	i = 0;
	while (i < data->map_height)
	{
		tab_width[i] = ft_strlen(data->map[i]);
		i++;
	}
	i = 0;
	j = i + 1;
	while (i < data->map_height)
	{
		while (j < data->map_height)
		{
			if (tab_width[i] != tab_width[j])
				return (free(tab_width), -1);
			j++;
		}
		j = i + 1;
		i++;
	}
	return (0);
}

void	ft_print_err(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
}
