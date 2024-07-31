#include "cube3d.h"

static void	_mm_build_minimap(mlx_image_t *minimap)
{
	t_datamodel	*dm;
	int			y;
	int			x;
	int			px;
	int			py;


	dm = dm_get(NULL);
	y = 0;
	x = 0;
	px = 0;
	py = 0;
	while (y < dm->tilemap->size.y)
	{
		while( x < dm->tilemap->size.x)
		{
			char debug = dm->tilemap->map[y][x];
			(void)debug;
			while (py < MM_RES)
			{
				while (px < MM_RES)
				{
					if (dm->tilemap->map[y][x] == '1')
						mlx_put_pixel(minimap, px + (x * MM_RES), py + (y * MM_RES), 0xFFFFFFFF);
					else
						mlx_put_pixel(minimap, px + (x * MM_RES), py + (y * MM_RES), 0x000000FF);
					px++;
				}
				px = 0;
				py++;
			}
			py = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

void	mm_setup(t_datamodel *dm)
{
	mlx_image_t *minimap;
	
	minimap =  mlx_new_image(dm->mlx, dm->tilemap->size.x * MM_RES, dm->tilemap->size.y * MM_RES);
	_mm_build_minimap(minimap);
	mlx_loop_hook(dm->mlx, mm_draw_minimap, minimap);
}

