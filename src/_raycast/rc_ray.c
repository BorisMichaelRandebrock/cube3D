#include "cube3d.h"
#include <math.h>

#define RAY_LENGTH 0.01
#include <stdio.h>



void	rc_cast(void *ray)
{
	float		distance;
	t_datamodel	*dm;
	t_point		endpoint;
	t_ray		*_ray;

	dm = dm_get(NULL);
	_ray = (t_ray *)ray;
	endpoint = dm->player->pos;
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		endpoint.x += RAY_LENGTH * cosf(dm->player->orientation);
		endpoint.y += RAY_LENGTH * sinf(dm->player->orientation);
	}
 	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = ut_abs(distance);
}

void	rc_cast_offset(void *ray, float rad_offset)
{
	float		distance;
	t_datamodel	*dm;
	t_point		endpoint;
	t_ray		*_ray;

	dm = dm_get(NULL);
	_ray = (t_ray *)ray;
	endpoint = dm->player->pos;
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		endpoint.x += RAY_LENGTH * cosf(dm->player->orientation + rad_offset);
		endpoint.y += RAY_LENGTH * sinf(dm->player->orientation + rad_offset);
	}
 	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = ut_abs(distance);
}

void	rc_cast_fan(void *s_ray)
{
	t_ray		*ray;
//	t_datamodel	*dm;
	float		rad_offset;
	int			i;

//	dm = dm_get(NULL);
	ray = (t_ray *)s_ray;
	i = 0;
	while (i < 60)
	{
		rad_offset = ut_deg_to_rad(i - 30);
		rc_cast_offset(ray + i, rad_offset);
		i++;
	}	
}
