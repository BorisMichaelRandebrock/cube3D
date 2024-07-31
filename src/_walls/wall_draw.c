#include "cube3d.h"

void	wall_draw(void *wallimg)
{
	t_datamodel	*dm;
	mlx_image_t	*_wallimg;
	float		new_height;

	dm = dm_get(NULL);
	_wallimg = (mlx_image_t *)wallimg;
	new_height = V_RES / dm->front_ray->length;
	mlx_resize_image(_wallimg, _wallimg->width, new_height);
	_wallimg->instances[0].y = (V_RES /2) - (new_height / 2);
}