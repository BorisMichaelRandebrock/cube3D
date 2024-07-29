#include <stdio.h>
#include "cube3d.h"


//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
//void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param)
void	input_init(mlx_key_data_t keydata, void *param)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_terminate(param);
		exit(EXIT_SUCCESS);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		printf("strafe left");
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		printf("strafe right");
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		printf("move forawrd");
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		printf("move back");
	else if ((keydata.key == MLX_KEY_LEFT  || keydata.key == MLX_KEY_Q)  
			&& keydata.action == MLX_REPEAT)
		printf("look left");
	else if ((keydata.key == MLX_KEY_RIGHT  || keydata.key == MLX_KEY_E)  
			&& keydata.action == MLX_REPEAT)
		printf("look right");
}
