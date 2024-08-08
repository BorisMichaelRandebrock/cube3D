#include "cube3d.h"
#include <math.h>






void	wall_draw(void *unused)
{
	t_datamodel	*dm;
	mlx_image_t	*img;
	double		new_height;
	t_texture	*_walltex;
	t_ray		*ray;

	(void)unused;
	dm = dm_get(NULL);
	t_list	*_ray_list = dm->ray_list;
	int i = 0;
	while (_ray_list)
	{
		ray = ((t_ray *)_ray_list->content);
		_walltex = dm->wall_tex[ray->wall_side];
		img = dm->columns[i++];
		new_height = V_RES / ray->length;
		mlx_resize_image(img, 1 , new_height);

		uint32_t sy = 0;
		uint32_t dy = 0;
		while (dy < new_height - 1)
		{
			if (sy > 255)
				break ;

			double ratio = new_height / 256;
			sy = dy / ratio; 

			uint32_t pixel = _walltex->pixels[sy][ray->h_tex_pos];
			pixel = px_pixel_shader(pixel, ray->length);
			mlx_put_pixel(img, 0, dy, pixel);
			dy++;
		}
		
		// mover a la columna
		img->instances[0].x = ray->h_pos;
		img->instances[0].y = (V_RES /2) - (new_height / 2);
	
		
		_ray_list = _ray_list->next;
		mlx_set_instance_depth(&img->instances[0],1);
	}
}