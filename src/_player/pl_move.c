#include "cube3d.h"
#include <math.h>

#define MOVE_SPEED 0.2
#define ROT_SPEED 0.05

//TODO factor in delta time
void	pl_walk(int vect, float rad_mod)
{
	t_datamodel	*dm;
	float		delta_x;
	float		delta_y;

	dm = dm_get(NULL);
	delta_x = vect * (MOVE_SPEED * cosf(dm->player->orientation + rad_mod));
	delta_y = vect * (MOVE_SPEED * sinf(dm->player->orientation + rad_mod));
	dm->player->pos.x += delta_x;
	dm->player->pos.y += delta_y;
}

void	pl_rotate(float rotation)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	dm->player->orientation += rotation * ROT_SPEED;
}
