#include <math.h>
#include "cube3d.h"

#define RAY_LENGTH 0.01

static t_point	_get_next_step(t_point endpoint, double orientation)
{
	t_point	direction;
	direction = ut_get_direction(orientation);
	(void)direction;

	endpoint.x += RAY_LENGTH * cos(orientation);
	endpoint.y += RAY_LENGTH * sin(orientation);
	return (endpoint);
}

void	rc_dda(void *ray)
{
	double		distance;
	t_datamodel	*dm;
	t_point		endpoint;
	t_ray		*_ray;

	dm = dm_get(NULL);
	_ray = (t_ray *)ray;
	endpoint = dm->player->pos;
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
		endpoint = _get_next_step(endpoint, dm->player->orientation);
	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = fabs(distance);
}


void	rc_cast(void *ray)
{
	double		distance;
	t_datamodel	*dm;
	t_point		endpoint;
	t_ray		*_ray;

	dm = dm_get(NULL);
	_ray = (t_ray *)ray;
	endpoint = dm->player->pos;
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		endpoint.x += RAY_LENGTH * cos(dm->player->orientation);
		endpoint.y += RAY_LENGTH * sin(dm->player->orientation);
	}
 	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = fabs(distance);
}

void	rc_cast_offset(void *ray, double radians)
{
	double		distance;
	t_datamodel	*dm;
	t_point		endpoint;
	t_ray		*_ray;

	dm = dm_get(NULL);
	_ray = (t_ray *)ray;
	endpoint = dm->player->pos;
	while (dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
	{
		endpoint.x += RAY_LENGTH * cos(dm->player->orientation + radians);
		endpoint.y += RAY_LENGTH * sin(dm->player->orientation + radians);
	}
 	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = fabs(distance);
}

void	rc_cast_fan(void *dm)
{
	t_ray		*ray;
	double		radians;
	double		fov;
	int			columns;
	t_datamodel	*_dm;

	_dm = (t_datamodel *)dm;
	columns = H_RES;
	fov = 60;
	ft_lstclear(&_dm->ray_list, free);
	while (columns)
	{
		ray = ut_scalloc(1, sizeof(t_ray));
		ray->h_pos = columns--;
		radians = ut_deg_to_rad(fov - 30); //TODO arreglar esto con los radianes bien!
		rc_cast_offset(ray, radians);
		ft_lstadd_back(&_dm->ray_list, ft_lstnew(ray));
		fov -= fov / H_RES;
	}

}
