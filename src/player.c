#include "cube3d.h"
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.2

void	move_player(t_point move)
{
	t_datamodel	*dm;

	dm = get_dm(NULL);
	dm->player->pos.x += (move.x * MOVE_SPEED);
	dm->player->pos.y += (move.y * MOVE_SPEED);
}

void	rotate_player(float rotation)
{
	t_datamodel	*dm;

	dm = get_dm(NULL);
	dm->player->orientation += (rotation * ROT_SPEED);
}
