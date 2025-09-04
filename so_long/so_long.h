/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:44:26 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/04 17:57:01 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

#define SIZE_X 800
#define SIZE_Y 600
#define SPRITES_PATH "Sprites"

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_mlx_data
{
	char		**map;
	int			map_width;
	int			map_height;
	void		*mlx_connection;
	void		*win;
	int			win_width;
	int			win_height;
	t_player	player_pos;
	t_img		*player;
	t_img		*background;
	t_img		*wall;
	t_img		*collectible;
	t_img		*exit;
}				t_mlx_data;

int				ft_init_mlx_data(t_mlx_data *data, char *win_title,
					int win_width, int win_height);
int				ft_init_data_map(t_mlx_data *data, char *filename);

int				ft_check_map(t_mlx_data *data);
int				ft_check_init_width(t_mlx_data *data);

int				ft_generate_images(t_mlx_data *data);
void			ft_generate_map(char **map, size_t width, size_t height,
					t_mlx_data *data);

int				ft_handle_key(int keycode, t_mlx_data *data);

void			ft_destroy_images(t_mlx_data *data);

void			ft_print_err(char *err_msg);
