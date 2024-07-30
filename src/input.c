#include <stdio.h>
#include "cube3d.h"

void	close_game(void *param)
{
	mlx_terminate(param);
	exit(EXIT_SUCCESS);
}

void	input_init(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_game(param);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		move_player_walk(-1, deg_to_rad(90));
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		move_player_walk(1, deg_to_rad(90));
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_player_walk(1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		move_player_walk(-1, 0);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_Q)
		&& keydata.action == MLX_REPEAT)
		rotate_player(-1);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_E)
		&& keydata.action == MLX_REPEAT)
		rotate_player(1);
}
