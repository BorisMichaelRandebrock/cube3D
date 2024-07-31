#include "cube3d.h"
#include <math.h>

#define RAY_LENGTH 0.001
#include <stdio.h>

float	rc_cast(void)
{
	float		distance;
	t_datamodel	*dm;
	t_point		endpoint;

	dm = dm_get(NULL);
	endpoint = dm->player->pos;
	endpoint.x = RAY_LENGTH * cosf(dm->player->orientation);
	endpoint.y = RAY_LENGTH * sinf(dm->player->orientation);
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		endpoint.x += RAY_LENGTH * cosf(dm->player->orientation);
		endpoint.y += RAY_LENGTH * sinf(dm->player->orientation);
	}
	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	return (distance);
}


/* float	rc_cast(void)
{
	float		distance;
	t_datamodel	*dm;
	t_point		spoint;
	t_point		endpoint;

	dm = get_dm(NULL);
	distance = 0;
	spoint = dm->player->pos;
	endpoint.x = (spoint.x + RAY_LENGTH) * cosf(dm->player->orientation);
	endpoint.y = (spoint.y + RAY_LENGTH) * sinf(dm->player->orientation);
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		spoint = endpoint;
		endpoint.x = (spoint.x + RAY_LENGTH) * cosf(dm->player->orientation);
		endpoint.y = (spoint.y + RAY_LENGTH) * sinf(dm->player->orientation);
	}
	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	return (distance);
} */
