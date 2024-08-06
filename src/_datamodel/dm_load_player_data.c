#include "cube3d.h"
#include "rad.h"

#define	MM_SIZE	16

void	dm_load_player_data(t_datamodel *dm)
{
	char	c;

	dm->player = ut_scalloc(1,sizeof(t_player));
	dm->player->pos = dm->tilemap->spawn_point;
	c = dm->tilemap->spawn_char;
	if (c == 'N')
		dm->player->orientation = RAD_90;
	else if (c == 'S')
		dm->player->orientation = RAD_270;
	else if (c == 'W')
		dm->player->orientation = RAD_180;
	else if (c == 'E')
		dm->player->orientation = RAD_0;
	dm->player->orientation *= -1;
	dm->player->coldet_ray = ut_scalloc(1,sizeof(t_ray));
	dm->player->mm_size = MM_SIZE;
}