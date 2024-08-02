#include "cube3d.h"

void    dm_populate_columns(t_datamodel *dm)
{
	int             i;
	mlx_texture_t   *blank_texture;
	mlx_image_t     *col;
	
	i = 0;
	blank_texture = mlx_load_png("res/blank.png");
	while (i < H_RES)
	{
		col = mlx_texture_to_image(dm->mlx, blank_texture);
		mlx_image_to_window(dm->mlx, col,i, 0);
		col->enabled = false;
		dm->wall_columms[i++] = col;
	}
}