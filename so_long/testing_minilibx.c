/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_minilibx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:34:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/02 21:08:09 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			handle_key_input(int keycode, t_mlx_data *data);
t_img		*ft_convert_xpm_to_images(void *mlx_connection, char *path);

int	main(void)
{
	t_mlx_data	*data;

	srand(time(NULL));
	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (1);
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		return (1);
	data->win = mlx_new_window(data->mlx_connection, SIZE_X, SIZE_Y,
			"ARRI POTTAIRE");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		return (1);
	}
	mlx_key_hook(data->win, handle_key_input, data);
	data->player = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/player1.xpm");
	if (!data->player)
		return (1);
	data->background = ft_convert_xpm_to_images(data->mlx_connection,
			SPRITES_PATH "/background.xpm");
	if (!data->background)
		return (1);
	for (int x = 0; x < SIZE_X; x += 32)
	{
		for (int y = 0; y < SIZE_Y; y += 32)
		{
			mlx_put_image_to_window(data->mlx_connection, data->win,
				data->background, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx_connection, data->win,
		data->player, 400, 300);
	mlx_loop(data->mlx_connection);
	return (0);
}



/**
 * Handles keyboard input events for the application.
 *
 * When the ESC key is pressed, all allocated memory is freed before exiting.
 * The mlx_destroy_window() function frees the data->win pointer among other
 * cleaning operations, whereas with mlx_destroy_display() we still need to free
 * data->mlx_connection.
 *
 * @param keycode The code of the key that was pressed.

	* @param data Pointer to the MLX data structure containing application state.
 * @return Returns an integer status code (typically 0 for success,
	or other values for error handling).
 */
int	handle_key_input(int keycode, t_mlx_data *data)
{
	int	x_pos;
	int	y_pos;

	printf("You pressed the key %d\n", keycode);
	if (keycode == XK_Escape)
	{
		printf("ESC key pressed. Cleaning up and exiting program...\n");
		mlx_destroy_window(data->mlx_connection, data->win);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		free(data);
		printf("KTHXBYYYEEE\n");
		exit(0);
	}
	x_pos = rand() % SIZE_X;
	y_pos = rand() % SIZE_Y;
	mlx_pixel_put(data->mlx_connection, data->win, x_pos, y_pos,
		0x9932FF);
	return (0);
}
