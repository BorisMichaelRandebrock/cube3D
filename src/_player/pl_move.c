#include <math.h>
#include "cube3d.h"
#include "rad.h"
#include "float.h"

#define MOVE_SPEED 0.2
#define ROT_SPEED 0.05
#define COLDET_SCALE 0.3

static bool	pl_sat_coldet(t_datamodel *dm, t_point delta)
{
	t_coldet_rect	rect;

	rect.top_left.x = delta.x - (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.top_left.y = delta.y - (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.bottom_right.x = delta.x + (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.bottom_right.y = delta.y + (dm->player->mm_size / MM_RES) * COLDET_SCALE;

	if (dm->tilemap->map[(int)rect.top_left.y][(int)rect.top_left.x] == '1'
		|| dm->tilemap->map[(int)rect.bottom_right.y][(int)rect.top_left.x] == '1'
		|| dm->tilemap->map[(int)rect.bottom_right.y][(int)rect.bottom_right.x] == '1'
		|| dm->tilemap->map[(int)rect.top_left.y][(int)rect.bottom_right.x] == '1')
		return (true);
	return (false);
}
//TODO factor in delta time
void	pl_walk(int mag, double radians)
{
	t_datamodel	*dm;
	t_point		delta;

	dm = dm_get(NULL);
	delta =  dm->player->pos;
	delta.x += mag * MOVE_SPEED * ut_cos(dm->player->yaw + radians);
	delta.y += mag * MOVE_SPEED * ut_sin(dm->player->yaw + radians);
	if (pl_sat_coldet(dm, delta))
		return ;
	dm->player->pos = delta;
}

void	pl_rotate(int mag)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	dm->player->yaw += (mag * ROT_SPEED);
	dm->player->yaw = ut_norm_angle(dm->player->yaw);
}