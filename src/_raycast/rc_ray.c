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

void	rc_cast_fan(t_list **ray_list)
{
	t_ray		*ray;
	float		rad_offset;
	float		fov;
	int			i;

	//TODO check si faltan columnas
	i = H_RES;
	fov = 60;
	while (i)
	{
		ray = ut_scalloc(1, sizeof(t_ray));
		ray->h_pos = i--;
		rad_offset = ut_deg_to_rad(fov);
		rc_cast_offset(ray, rad_offset);
		ft_lstadd_back(ray_list, ft_lstnew(ray));
		fov -= fov /H_RES;
	}	
}
