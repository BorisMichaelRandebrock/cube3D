#include "cube3d.h"

void	mm_draw_minimap(void *minimap)
{
	t_datamodel	*dm;
	mlx_image_t	*_minimap;

	_minimap = (mlx_image_t *)minimap;
	dm = dm_get(NULL);
	mlx_image_to_window(dm->mlx, _minimap, 0, 0);
}

