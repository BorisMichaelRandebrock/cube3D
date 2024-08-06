#include <math.h>
#include "cube3d.h"
#include "rad.h"
#include "float.h"

#define MOVE_SPEED 0.2
#define ROT_SPEED 0.05

//TODO factor in delta time
void	pl_walk(int mag, double radians)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	rc_cast_offset(dm->player->coldet_ray, radians);
	if (dm->player->coldet_ray->length * MM_RES <= dm->player->mm_size)
		return ;
	dm->player->pos.x += mag * MOVE_SPEED * cos(dm->player->orientation + radians);
	dm->player->pos.y += mag * MOVE_SPEED * sin(dm->player->orientation + radians);
}


void	pl_rotate(int mag)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	dm->player->orientation += -1 * (mag * ROT_SPEED);
}