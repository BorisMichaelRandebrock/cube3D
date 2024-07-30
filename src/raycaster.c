#include "cube3d.h"
#include <math.h>

#define RAY_LENGTH 0.001
#include <stdio.h>

void	draw_wall(void *img)
{
	mlx_t			*_mlx = get_dm(NULL)->mlx;
	mlx_image_t		*wallimg = (mlx_image_t *)img;
	
	float	ray = cast_ray();
	float	new_heigth = clamp (1, V_RES, (V_RES / ray));
	
	mlx_resize_image(wallimg,10, new_heigth);
	printf("height: %f - ray: %f - ppos: %f,%f\n", new_heigth, ray, get_dm(NULL)->player->pos.x, get_dm(NULL)->player->pos.y);


	mlx_image_to_window(_mlx, wallimg, ((H_RES /2) - (wallimg->width / 2)), ((V_RES - new_heigth)/2));
}


float	cast_ray(void)
{
	float		distance;
	t_datamodel	*dm;
	t_point		endpoint;

	dm = get_dm(NULL);
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


/* float	cast_ray(void)
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
