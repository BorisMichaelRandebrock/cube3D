#include  "cube3d.h"

void	bg_setup(t_datamodel *dm)
{	
	mlx_image_t	*top;
	mlx_image_t	*bottom;
	int y;
	int x;

	top = mlx_new_image(dm->mlx, H_RES, V_RES / 2);
	bottom = mlx_new_image(dm->mlx, H_RES, V_RES / 2);
	x = 0;
	y = 0;
	while (y < V_RES / 2)
	{
		while (x < H_RES)
		{
			mlx_put_pixel(top,x,y, dm->ceiling_hex);
			mlx_put_pixel(bottom,x,y, dm->floor_hex);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(dm->mlx, top, 0, 0);
	mlx_image_to_window(dm->mlx, bottom, 0, V_RES / 2);
}