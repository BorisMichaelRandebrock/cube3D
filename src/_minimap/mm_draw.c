#include <math.h>
#include "cube3d.h"

#define PLAYER_SIZE 10

void	mm_draw_player(void *player)
{
	t_datamodel	*dm;
	mlx_instance_t	*_player;
	double		x;
	double		y;

	dm = dm_get(NULL);
	x = dm->player->pos.x * MM_RES;
	y = dm->player->pos.y * MM_RES;
	_player = (mlx_instance_t *)player;
	_player->x = x - (PLAYER_SIZE / 2);
	_player->y = y - (PLAYER_SIZE / 2);
	mlx_set_instance_depth(_player, 11);
}

void	mm_draw_destination(void *marker)
{
	t_datamodel		*dm;
	mlx_instance_t	*_marker;

	dm = dm_get(NULL);
	_marker = (mlx_instance_t *)marker;
	_marker->x = (dm->front_ray->endpoint.x * MM_RES);
	_marker->y = (dm->front_ray->endpoint.y * MM_RES);
	mlx_set_instance_depth(_marker, 11);
}

void	mm_draw_heading(void *heading)
{
	t_datamodel		*dm;
	mlx_instance_t	*_heading;

	dm = dm_get(NULL);
	_heading = (mlx_instance_t *)heading;
	_heading->x = (dm->player->pos.x) * MM_RES;
	_heading->y = (dm->player->pos.y) * MM_RES;
	_heading->x += cos(dm->player->rad) * MM_RES;
	_heading->y += sin(dm->player->rad) * MM_RES;
	mlx_set_instance_depth(_heading, 12);
}