#include "cube3d.h"

#define PLAYER_SIZE 16
#define MARKER_SIZE 8

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
	_player->x = x - (PLAYER_SIZE / 2);
	_player->y = y - (PLAYER_SIZE / 2);
}

void	mm_draw_destination(void *marker)
{
	t_datamodel		*dm;
	mlx_instance_t	*_marker;

	dm = dm_get(NULL);
	_marker = (mlx_instance_t *)marker;
	_marker->x = (dm->front_ray->endpoint.x * MM_RES) - (MARKER_SIZE / 2);
	_marker->y = (dm->front_ray->endpoint.y * MM_RES) - (MARKER_SIZE / 2);
}