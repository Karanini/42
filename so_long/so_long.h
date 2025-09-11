/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:44:26 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/11 15:56:20 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

#define SIZE_X 800
#define SIZE_Y 600
#define SPRITES_PATH "Sprites"

typedef struct s_init_data_map
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;
}			t_init_data_map;

typedef struct s_game_data
{
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		nb_moves;
	int		nb_collectibles_left;
}			t_game;

typedef struct s_mlx_data
{
	char	**map;
	int		map_width;
	int		map_height;
	void	*mlx_connection;
	void	*win;
	int		win_width;
	int		win_height;
	t_game	*game_data;
	t_img	*player;
	t_img	*background;
	t_img	*wall;
	t_img	*collectible;
	t_img	*exit;
	int		error_code;
}			t_mlx_data;

t_mlx_data	*ft_init_t_mlx_data(void);
t_game		*ft_init_t_game_data(void);
int			ft_init_mlx_ptr_and_win(t_mlx_data *data, char *win_title);
void		ft_init_player_and_exit_pos(t_mlx_data *data);

int			ft_init_data_map(t_mlx_data *data, char *filename);

int			ft_check_map(t_mlx_data *data);
int			ft_check_walls(t_mlx_data *data);
int			ft_check_screen_size(t_mlx_data *data);
int			ft_check_reachable_items(t_mlx_data *data);

int			ft_generate_images(t_mlx_data *data);
void		ft_generate_map(t_mlx_data *data);

int			ft_handle_key(int keycode, t_mlx_data *data);

void		ft_move_player_y(int keycode, t_mlx_data *data);
void		ft_move_player_x(int keycode, t_mlx_data *data);

void		ft_destroy_images(t_mlx_data *data);
int			ft_cleanup(t_mlx_data *data, int exit_code);
void		ft_cleanup_imap(t_init_data_map *imap);
int			ft_exit_on_destroy(t_mlx_data *data);

void		ft_print_err(char *err_msg);
void		ft_print_err_EPC(int count, char to_check);
void		ft_print_map(t_mlx_data *data);
void		ft_print_player_pos(t_game *game_data);
