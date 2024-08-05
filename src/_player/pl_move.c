#include <math.h>
#include "cube3d.h"
#include "rad.h"

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
//TODO comprobar esto...
void	pl_rotate(float rotation)
{
	t_datamodel	*dm;
	float		mod;
	
	dm = dm_get(NULL);
	mod = rotation * ROT_SPEED;
	if (mod + dm->player->orientation < RAD_0)
		dm->player->orientation = RAD_360 + (mod + dm->player->orientation);
	else if (mod + dm->player->orientation > RAD_360)
		dm->player->orientation = RAD_0 + ((mod + dm->player->orientation) - RAD_360);
	else
		dm->player->orientation += mod;
}
