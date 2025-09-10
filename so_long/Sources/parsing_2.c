/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:56:54 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/09 16:36:10 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			return (-1);
		y++;
	}
	while (x < data->map_width)
	{
		if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

static void	ft_flood_fill(char ***map, int y, int x, t_mlx_data *data)
{
	// int	i;

	// i = 0;
	// // ft_printf("y: %d\n", y);
	// ft_printf("x %d\n", x);
	// if (*map)
	// {
	// 	while ((*map)[i])
	// 	{
	// 		ft_printf("%s\n", (*map)[i]);
	// 		i++;
	// 	}
	// }
	ft_putstr_fd("\n", 1);
	if ((*map)[y][x] == 'E')
		(*map)[y][x] = 'e';
	if ((*map)[y][x] == 'C')
		(*map)[y][x] = 'c';
	if ((*map)[y][x] == '0')
		(*map)[y][x] = 'o';
	if ((y - 1) > 0 && (*map)[y - 1][x] != '1' && (*map)[y - 1][x] != 'e'
		&& (*map)[y - 1][x] != 'c' && (*map)[y - 1][x] != 'o')
		ft_flood_fill(map, y - 1, x, data);
	if ((x + 1) < data->map_width && (*map)[y][x + 1] != '1' && (*map)[y][x
		+ 1] != 'e' && (*map)[y][x + 1] != 'c' && (*map)[y][x + 1] != 'o')
		ft_flood_fill(map, y, x + 1, data);
	if ((y + 1) < data->map_height && (*map)[y + 1][x] != '1' && (*map)[y
		+ 1][x] != 'e' && (*map)[y + 1][x] != 'c' && (*map)[y + 1][x] != 'o')
		ft_flood_fill(map, y + 1, x, data);
	if ((x - 1) > 0 && (*map)[y][x - 1] != '1' && (*map)[y][x - 1] != 'e'
		&& (*map)[y][x - 1] != 'c' && (*map)[y][x - 1] != 'o')
		ft_flood_fill(map, y, x - 1, data);
}

static char	**ft_dup_map(t_mlx_data *data)
{
	char	**map;
	int		y;

	map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!map)
		return (NULL);
	y = 0;
	while (y < data->map_height)
	{
		map[y] = ft_strdup(data->map[y]);
		if (!map[y])
			return (free_tab(map), NULL);
		y++;
	}
	map[y] = NULL;
	return (map);
}

int	ft_check_reachable_items(t_mlx_data *data)
{
	char	**dup_map;
	int		x;
	int		y;
	// int		i;

	x = 0;
	y = 0;
	dup_map = ft_dup_map(data);
	if (!dup_map)
		return (1);
	// i = 0;
	// if (dup_map)
	// {
	// 	ft_printf("dup_map:\n\n");
	// 	while (dup_map[i])
	// 	{
	// 		ft_printf("%s\n", dup_map[i]);
	// 		i++;
	// 	}
	// }
	// ft_printf("\nend dup_map\n");
	ft_flood_fill(&dup_map, data->game_data->player_y,
		data->game_data->player_x, data);
	while (dup_map[y])
	{
		while (dup_map[y][x])
		{
			if (dup_map[y][x] == 'E' || dup_map[y][x] == 'C')
				return (free_tab(dup_map), -1);
			x++;
		}
		x = 0;
		y++;
	}
	free_tab(dup_map);
	return (0);
}
