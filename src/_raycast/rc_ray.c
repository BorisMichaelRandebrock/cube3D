/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:13:21 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include <stdio.h>

#define RAY_LENGTH		0.01
#define WALL_N			0
#define WALL_E			1
#define WALL_S			2
#define WALL_W			3

//TODO implementar DDA algo
/* static t_point	_get_next_step(t_point endpoint, double yaw)
{
	(void)endpoint;
	(void)yaw;
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
	while (endpoint.x > 0 && endpoint.y > 0
		&& dm->tilemap->map[(int)endpoint.y][(int)endpoint.x] != '1')
		endpoint = _get_next_step(endpoint, dm->player->yaw);
	distance = sqrt(pow(endpoint.x - dm->player->pos.x, 2)
			+ pow(endpoint.y - dm->player->pos.y, 2));
	_ray->endpoint = endpoint;
	_ray->length = fabs(distance);
} */

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

static void	_get_ray_data(t_datamodel *dm, t_ray *ray)
{
	if (fabs(ray->endpoint.x - round(ray->endpoint.x))
		> fabs(ray->endpoint.y - round(ray->endpoint.y)))
	{
		ray->h_tex_pos = fabs(256 * (ray->endpoint.x - trunc(ray->endpoint.x)));
		if (ray->endpoint.y - dm->player->pos.y < 0)
			ray->wall_side = WALL_S;
		else
			ray->wall_side = WALL_N;
	}
	else
	{
		ray->h_tex_pos = fabs(256 * (ray->endpoint.y - trunc(ray->endpoint.y)));
		if (ray->endpoint.x - dm->player->pos.x < 0)
			ray->wall_side = WALL_W;
		else
			ray->wall_side = WALL_E;
	}
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
		radians = ut_deg_to_rad(fov - 30);
		rc_cast_offset(ray, radians);
		_get_ray_data(dm, ray);
		ft_lstadd_back(&_dm->ray_list, ft_lstnew(ray));
		fov -= fov / H_RES;
	}
}
