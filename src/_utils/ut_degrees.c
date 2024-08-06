#include <math.h>
#include "cube3d.h"
#include "rad.h"

//TODO borrar conversiones
double	ut_deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

//TODO borrar conversiones
double	ut_rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

t_point	ut_get_direction(double radians)
{
	t_point	direction;

	direction.x = ut_cos(radians);
	direction.y = ut_sin(radians);

	if (direction.x < 0 - RADTOL)
		direction.x = -1;
	else
		direction.x = 1;
	if (direction.y < 0 - RADTOL)
		direction.y = -1;
	else
		direction.y = 1;

	return (direction);
}