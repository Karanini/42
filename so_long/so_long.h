/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:44:26 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/03 15:46:11 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"

#define SIZE_X 800
#define SIZE_Y 600
#define SPRITES_PATH "Sprites"

typedef struct s_mlx_data
{
	void	*mlx_connection;
	void	*win;
	t_img	*player;
	t_img	*background;
	t_img	*wall;
	t_img	*collectible;
	t_img	*exit;
}			t_mlx_data;

t_mlx_data	*ft_init_mlx_data(char *win_title);
int			ft_generate_images(t_mlx_data *data);
void		ft_generate_map(char **map, size_t width, size_t height,
				t_mlx_data *data);

void		ft_destroy_images(t_mlx_data *data);
