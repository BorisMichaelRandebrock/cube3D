#include "cube3d.h"
#include <stdio.h>

void	wall_setup(t_datamodel *dm)
{
	t_timon *timon = ut_scalloc(1, sizeof(t_timon));
	mlx_texture_t	*texture;

	
	texture = mlx_load_png("res/blank.png");
	int i = 0 ;

	while (i < H_RES)
	{
		timon->img[i] = mlx_texture_to_image(dm->mlx, texture);
		mlx_image_to_window(dm->mlx, timon->img[i], 0,0);
		i++;
	}
	mlx_loop_hook(dm->mlx, rc_cast_fan, dm);
	mlx_loop_hook(dm->mlx, wall_draw, timon);
}
