#include "cube3d.h"

void	mm_draw_player(void *player)
{
	t_datamodel	*dm;
	mlx_instance_t	*_player;
	float		x;
	float		y;

	dm = dm_get(NULL);
	x = dm->player->pos.x * MM_RES;
	y = dm->player->pos.y * MM_RES;
	_player = (mlx_instance_t *)player;
	_player->x = x;
	_player->y = y;
}