#include "cube3d.h"

#define	MM_SIZE	12
#define	E_DEG	0
#define	N_DEG	90
#define	W_DEG	180
#define	S_DEG	270

void	dm_load_player_data(t_datamodel *dm)
{
	char	c;

	dm->player = ut_scalloc(1,sizeof(t_player));
	dm->player->pos = dm->tilemap->spawn_point;
	c = dm->tilemap->spawn_char;
	if (c == 'N')
		dm->player->orientation = ut_deg_to_rad(N_DEG);
	else if (c == 'S')
		dm->player->orientation = ut_deg_to_rad(S_DEG);
	else if (c == 'W')
		dm->player->orientation = ut_deg_to_rad(W_DEG);
	else if (c == 'E')
		dm->player->orientation = ut_deg_to_rad(E_DEG);
	dm->player->coldet_ray = ut_scalloc(1,sizeof(t_ray));
	dm->player->mm_size = MM_SIZE;
}