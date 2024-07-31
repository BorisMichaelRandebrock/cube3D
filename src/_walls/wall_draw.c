#include <stdio.h>
#include "cube3d.h"

void	wall_draw(void *img)
{
	mlx_t			*_mlx = dm_get(NULL)->mlx;
	mlx_image_t		*wallimg = (mlx_image_t *)img;
	
	float	ray = rc_cast();
	float	new_heigth = ut_clamp (1, V_RES, (V_RES / ray));
	
	mlx_resize_image(wallimg,10, new_heigth);
	printf("height: %f - ray: %f - ppos: %f,%f\n", new_heigth, ray, dm_get(NULL)->player->pos.x, dm_get(NULL)->player->pos.y);

	mlx_image_to_window(_mlx, wallimg, ((H_RES /2) - (wallimg->width / 2)), ((V_RES - new_heigth)/2));
}