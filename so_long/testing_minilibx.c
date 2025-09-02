/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_minilibx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:34:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/09/02 12:27:32 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include "time.h"
#include <stdlib.h>

#define SIZE_X 800
#define SIZE_Y 600

typedef struct s_mlx_data
{
	void	*mlx_connection;
	void	*win;
}			t_mlx_data;

int			handle_key_input(int keycode, t_mlx_data *mlx_data);

int	main(void)
{
	t_mlx_data	*mlx_data;

	srand(time(NULL));
	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (1);
	mlx_data->mlx_connection = mlx_init();
	if (!mlx_data->mlx_connection)
		return (1);
	mlx_data->win = mlx_new_window(mlx_data->mlx_connection, SIZE_X, SIZE_Y,
			"ARRI POTTAIRE");
	if (!mlx_data->win)
	{
		mlx_destroy_display(mlx_data->mlx_connection);
		free(mlx_data->mlx_connection);
		return (1);
	}
	mlx_key_hook(mlx_data->win, handle_key_input, mlx_data);
	mlx_loop(mlx_data->mlx_connection);
	return (0);
}

/**
 * Handles keyboard input events for the application.
 *
 * When the ESC key is pressed, all allocated memory is freed before exiting.
 * The mlx_destroy_window() function frees the mlx_data->win pointer among other
 * cleaning operations, whereas with mlx_destroy_display() we still need to free
 * mlx_data->mlx_connection.
 *
 * @param keycode The code of the key that was pressed.

	* @param mlx_data Pointer to the MLX data structure containing application state.
 * @return Returns an integer status code (typically 0 for success,
	or other values for error handling).
 */
int	handle_key_input(int keycode, t_mlx_data *mlx_data)
{
	printf("You pressed the key %d\n", keycode);
	if (keycode == XK_Escape)
	{
		printf("ESC key pressed. Cleaning up and exiting program...\n");
		mlx_destroy_window(mlx_data->mlx_connection, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx_connection);
		free(mlx_data->mlx_connection);
		free(mlx_data);
		printf("KTHXBYYYEEE\n");
		exit(0);
	}
	int	x_pos = rand() % SIZE_X;
	int y_pos = rand() % SIZE_Y;
	mlx_pixel_put(mlx_data->mlx_connection, mlx_data->win, x_pos, y_pos, 0x9932FF);
	return (0);
}
