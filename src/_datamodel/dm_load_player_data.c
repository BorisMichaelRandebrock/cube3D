#include "cube3d.h"

#define	E_DEG 0.0
#define	N_DEG 90.0
#define	W_DEG 180.0
#define	S_DEG 270.0

void	dm_load_player_data(t_datamodel *dm)
{
	char    c;

	dm->player = scalloc(1,sizeof(t_player));
	dm->player->pos = dm->tilemap->spawn_point;
	c = dm->tilemap->spawn_char;
	if (c == 'N')
		dm->player->orientation = deg_to_rad(N_DEG);
	else if (c == 'S')
		dm->player->orientation = deg_to_rad(S_DEG);
	else if (c == 'W')
		dm->player->orientation = deg_to_rad(W_DEG);
	else if (c == 'E')
		dm->player->orientation = deg_to_rad(E_DEG);
}