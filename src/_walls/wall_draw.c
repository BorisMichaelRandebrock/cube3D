#include "cube3d.h"
#include <math.h>


#define SHADOW_DEPTH 0.25

static void	_pixel_shader(mlx_image_t *img, float distance)
{
	uint32_t	px = 0;
	uint32_t	py = 0;
	uint32_t	color = 0;
	uint32_t	temp = 0;


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

void	wall_draw(void *timon)
{
	t_datamodel	*dm;
	mlx_image_t	*_img;
	float		new_height;

	dm = dm_get(NULL);
	t_list	*_ray_list = dm->ray_list;
	t_timon	*_timon = (t_timon *)timon;

	int i = 0;
	while (_ray_list)
	{
		_img = _timon->img[i++];
		new_height = V_RES / ((t_ray *)_ray_list->content)->length;
		mlx_resize_image(_img, 1 , new_height);
		_img->instances[0].x = ((t_ray *)_ray_list->content)->h_pos;
		_img->instances[0].y = (V_RES /2) - (new_height / 2);
		_pixel_shader(_img, ((t_ray *)_ray_list->content)->length);
		_ray_list = _ray_list->next;
	}
}