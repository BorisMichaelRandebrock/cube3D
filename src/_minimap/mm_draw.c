#include "cube3d.h"

void	mm_draw_minimap(void *minimap)
{
	t_datamodel	*dm;
	mlx_image_t	*_minimap;
	int			instance;

	dm = dm_get(NULL);
	_minimap = (mlx_image_t *)minimap;
	instance = mlx_image_to_window(dm->mlx, _minimap, 0, 0);
	mlx_set_instance_depth(&_minimap->instances[instance], 1);
	
}

void	mm_draw_player(void *player)
{
	t_datamodel	*dm;
	mlx_image_t	*_player;
	int			instance;
	float		x;
	float		y;

	dm = dm_get(NULL);
	x = dm->player->pos.x * MM_RES;
	y = dm->player->pos.y * MM_RES;
	_player = (mlx_image_t *)player;
	instance = mlx_image_to_window(dm->mlx, _player, x, y);
	mlx_set_instance_depth(&_player->instances[instance], 2);
}