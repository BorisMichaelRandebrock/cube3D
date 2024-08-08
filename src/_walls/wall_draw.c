#include "cube3d.h"
#include <math.h>






void	wall_draw(void *walltex)
{
	t_datamodel	*dm;
	mlx_image_t	*img;
	double		new_height;
	t_texture	*_walltex;
	t_ray		*ray;

	dm = dm_get(NULL);
	t_list	*_ray_list = dm->ray_list;
	_walltex = (t_texture *)walltex;

	int i = 0;
	while (_ray_list)
	{
		ray = ((t_ray *)_ray_list->content);
		img = dm->columns[i++];
		new_height = V_RES / ray->length;
		mlx_resize_image(img, 1 , new_height);

		int y = 0;
		while (y < new_height - 1)
		{
			if (y > 255)
				break ;
			uint32_t pixel = _walltex->pixels[y][ray->h_tex_pos];
			pixel = px_pixel_shader(pixel, ray->length);
			mlx_put_pixel(img, 0, y, pixel);
			y++;
		}
		
		// mover a la columna
		img->instances[0].x = ray->h_pos;
		img->instances[0].y = (V_RES /2) - (new_height / 2);
	
		
		_ray_list = _ray_list->next;
		mlx_set_instance_depth(&img->instances[0],1);
	}
}