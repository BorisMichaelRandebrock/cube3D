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
		dm->player->rad = RAD_90;
	else if (c == 'S')
		dm->player->rad = RAD_270;
	else if (c == 'W')
		dm->player->rad = RAD_180;
	else if (c == 'E')
		dm->player->rad = RAD_0;
	dm->player->rad *= -1;
	dm->player->mm_size = MM_SIZE;
}