#include "cube3d.h"
#include <stdio.h>

void	wall_setup(t_datamodel *dm)
{
	(void)dm;

	mlx_loop_hook(dm->mlx, wall_draw, dm);
	/* while (ray_list)
	{
		printf("%f\n",((t_ray *)ray_list->content)->length);
		ray_list = ray_list->next;
	} */	
}
