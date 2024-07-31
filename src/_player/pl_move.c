#include "cube3d.h"
#include <math.h>

#define MOVE_SPEED 0.2
#define ROT_SPEED 0.05

//TODO factor in delta time
void	pl_walk(int mag, float rad_mod)
{
	t_datamodel	*dm;
	float		delta_x;
	float		delta_y;
	float		_rad_mod;

	dm = dm_get(NULL);
	if (mag < 0)
		_rad_mod = ut_rad_mirror(rad_mod);
	else
		_rad_mod = rad_mod;
	rc_cast_offset(dm->player->coldet_ray, _rad_mod);
	if (dm->player->coldet_ray->length * MM_RES <= dm->player->mm_size)
		return ;
	delta_x = (MOVE_SPEED * cosf(dm->player->orientation + _rad_mod));
	delta_y = (MOVE_SPEED * sinf(dm->player->orientation + _rad_mod));
	dm->player->pos.x += delta_x;
	dm->player->pos.y += delta_y;
}

void	pl_rotate(float rotation)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	dm->player->orientation += rotation * ROT_SPEED;
}
