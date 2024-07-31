#include <stdio.h>
#include "cube3d.h"

void	pl_input(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_game(param);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		pl_walk(-1, ut_deg_to_rad(90));
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		pl_walk(1, ut_deg_to_rad(90));
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		pl_walk(1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		pl_walk(-1, 0);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_Q)
		&& keydata.action == MLX_REPEAT)
		pl_rotate(-1);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_E)
		&& keydata.action == MLX_REPEAT)
		pl_rotate(1);
}
