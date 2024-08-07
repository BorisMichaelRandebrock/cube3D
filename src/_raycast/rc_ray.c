#include <math.h>
#include "cube3d.h"

#define RAY_LENGTH 0.01

static t_point	_get_next_step(t_point endpoint, double yaw)
{
	(void)endpoint;
	(void)yaw;
	return (endpoint);
	//TODO implementar DDA algo
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
	while (endpoint.x > 0 && endpoint.y > 0 && dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
		endpoint = _get_next_step(endpoint, dm->player->yaw);
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
		endpoint.x += RAY_LENGTH * ut_cos(dm->player->yaw);
		endpoint.y += RAY_LENGTH * ut_sin(dm->player->yaw);
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
		endpoint.x += RAY_LENGTH * ut_cos(dm->player->yaw + radians);
		endpoint.y += RAY_LENGTH * ut_sin(dm->player->yaw + radians);
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


		// (1.7 - 1) = 0.7
		if (ray->endpoint.x - trunc(ray->endpoint.x) > 0)
			ray->h_tex_pos = 256 * (ray->endpoint.x - trunc(ray->endpoint.x > 0));
		else
			ray->h_tex_pos = 256 * (ray->endpoint.y - trunc(ray->endpoint.y > 0));

		ft_lstadd_back(&_dm->ray_list, ft_lstnew(ray));
		fov -= fov / H_RES;
	}

}
