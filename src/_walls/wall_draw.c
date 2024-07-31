#include "cube3d.h"
#include <math.h>


#define SHADOW_DEPTH 0.2

void	shadow_pixel_shader(mlx_image_t *img, float distance)
{
	uint32_t	px = 0;
	uint32_t	py = 0;
	uint32_t	color = 0;
	uint32_t	temp = 0;
	//uint32_t	pd = 0;
/* 	mlx_texture_t	*tex;
	tex = mlx_load_png("res/blank.png"); */

	(void)distance;
	while (py < img->height)
	{
		while (px < img->width)
		{
			int	r = 0xFF / fmax(SHADOW_DEPTH * distance, 1);
			int	g = 0xFF / fmax(SHADOW_DEPTH * distance, 1);
			int	b = 0xFF /fmax(SHADOW_DEPTH * distance, 1);
			int	a = 0xFF;

			temp = r;
			temp <<= 24;
			color |= temp;

			temp = g;
			temp <<= 16;
			color |= temp;

			temp = b;
			temp <<= 8;
			color |= temp;

			temp = a;
			color |= temp;

			mlx_put_pixel(img, px, py, color);
			px++;
		}
		px = 0;
		py++;
	}
}

void	wall_draw(void *wallimg)
{
	t_datamodel	*dm;
	mlx_image_t	*_wallimg;
	float		new_height;

	dm = dm_get(NULL);
	_wallimg = (mlx_image_t *)wallimg;
	new_height = V_RES / dm->front_ray->length;
	mlx_resize_image(_wallimg, _wallimg->width, new_height);
	_wallimg->instances[0].y = (V_RES /2) - (new_height / 2);
	shadow_pixel_shader(_wallimg, dm->front_ray->length);
}