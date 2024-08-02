#include "cube3d.h"
#include <stdio.h>

void	wall_setup(t_datamodel *dm)
{
	t_timon *timon = ut_scalloc(1, sizeof(t_timon));
	mlx_texture_t	*texture;

	
	texture = mlx_load_png("res/blank.png");
	int i = 0 ;

	while (i < H_RES)
	{
		timon->img[i] = mlx_texture_to_image(dm->mlx, texture);
		mlx_image_to_window(dm->mlx, timon->img[i], 0,0);
		i++;
	}
	
	mlx_loop_hook(dm->mlx, rc_cast_fan, dm);
	mlx_loop_hook(dm->mlx, wall_draw, timon);
}

/* 
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
	ft_lstclear(&ray_start, free); */