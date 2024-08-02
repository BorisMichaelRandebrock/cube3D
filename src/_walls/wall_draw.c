#include "cube3d.h"
#include <math.h>


#define SHADOW_DEPTH 0.2

/* void	shadow_pixel_shader(mlx_image_t *img, float distance)
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
} */

void	wall_draw(void *dm)
{
	t_datamodel *_dm;
	t_list		*ray_list;
	t_list		*ray_start;
	t_ray		*ray;
	mlx_image_t	*col;

	_dm = (t_datamodel *)dm;
	ray_list = NULL;
	ray_start = ray_list;
	rc_cast_fan(&ray_list);
	ut_sort_rays(ray_list);
	while (ray_list)
	{
		ray = (t_ray *)ray_list->content;
		col = _dm->wall_columms[ray->h_pos - 1]; //TODO magic number
		mlx_resize_image(col, 1, V_RES / ray->length);
		col->enabled = true;
		ray_list = ray_list->next;
	}
	(void)ray_start;
	ft_lstclear(&ray_start, free);
}