/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:53:25 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 16:20:30 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_items(t_mlx_data *data, char to_check);
static int	ft_check_init_width(t_mlx_data *data);
static int	ft_check_valid_chars(t_mlx_data *data);
static int	*ft_set_tab_width(t_mlx_data *data);

int	ft_check_map(t_mlx_data *data)
{
	if (ft_check_valid_chars(data) == -1 || ft_check_items(data, 'E') == -1
		|| ft_check_items(data, 'P') == -1 || ft_check_items(data, 'C') == -1)
		return (-1);
	data->error_code = ft_check_init_width(data);
	if (data->error_code != 0)
		return (data->error_code);
	if (ft_check_walls(data) == -1)
		return (ft_print_err("You need to build more walls !!!"), -1);
	ft_init_player_and_exit_pos(data);
	data->error_code = ft_check_reachable_items(data);
	if (data->error_code == -1)
		return (ft_print_err("The player can't reach some elements!"), -1);
	else if (data->error_code == 1)
		return (ft_print_err("ft_dup_map malloc failed."), 1);
	return (0);
}

static int	ft_check_valid_chars(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] != 'E' && data->map[y][x] != 'P'
				&& data->map[y][x] != 'C' && data->map[y][x] != '0'
				&& data->map[y][x] != '1')
				return (ft_print_err("Unauthorized character detected:"),
					ft_printf("char %c\n", data->map[y][x]), -1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*
* Checks for the Exit Player and Collectible requirements.

* To optimize norm : handle error printing completely apart ? Sending
* to_check and count to this other function.

* leak checks if parsing fails: OK
*/
static int	ft_check_items(t_mlx_data *data, char to_check)
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
			if (data->map[y][x] == to_check)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	if (!count || (count > 1 && (to_check == 'E' || to_check == 'P')))
		return (ft_print_err_items(count, to_check), -1);
	if (count && to_check == 'C')
		data->game_data->nb_collectibles_left = count;
	return (0);
}

/*
 * @brief Checks and initializes the width of the map in the given data
 * structure.
 *
 * This function verifies if each line has the same width.
 *
 * @param data Pointer to the t_mlx_data structure containing map information.
 * @return int Returns 0 on success, 1 if a malloc error occurs,
	-1 if not all the width
 * are equal
 */
static int	ft_check_init_width(t_mlx_data *data)
{
	int	i;
	int	j;
	int	*tab_width;

	tab_width = ft_set_tab_width(data);
	if (!tab_width)
		return (data->error_code);
	i = 0;
	j = i + 1;
	while (i < data->map_height)
	{
		while (j < data->map_height)
		{
			if (tab_width[i] != tab_width[j])
				return (ft_print_err("The map is not rectangular."),
					free(tab_width), -1);
			j++;
		}
		j = i + 1;
		i++;
	}
	data->map_width = ft_strlen(data->map[0]);
	return (free(tab_width), 0);
}

static int	*ft_set_tab_width(t_mlx_data *data)
{
	int	*tab_width;
	int	i;

	tab_width = malloc(sizeof(int) * data->map_height);
	if (!tab_width)
		return (data->error_code = 1, NULL);
	i = 0;
	while (i < data->map_height)
	{
		tab_width[i] = ft_strlen(data->map[i]);
		if (tab_width[i] < 3)
			return (data->error_code = -1,
				ft_print_err("The map is too small."), free(tab_width), NULL);
		i++;
	}
	return (tab_width);
}
