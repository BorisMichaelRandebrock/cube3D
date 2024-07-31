#include "cube3d.h"

void	wall_setup(t_datamodel *dm)
{
	t_point		center;
	mlx_image_t	*wallimg;
	wallimg = mlx_texture_to_image(dm->mlx, mlx_load_png("res/blank.png"));

	center.x = (H_RES / 2) - (wallimg->width / 2);
	center.y = (V_RES /2) - (wallimg->height / 2);
	mlx_image_to_window(dm->mlx, wallimg, center.x, center.y);
	mlx_loop_hook(dm->mlx, wall_draw , wallimg);
}