#include <math.h>
#include "cube3d.h"
#include "rad.h"

double	ut_deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	ut_rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
/*
double	ut_rad_mirror(double radians)
{
	int	deg;

	deg = ut_rad_to_deg(radians);
	deg += 180;
	if (deg > 359)
		deg -= 360;
	return (ut_deg_to_rad(deg));
} */
//Note: (Y) Axis is inverted to fit MLX42 canvas coords...

t_point	ut_get_direction(double radians)
{
	t_point	direction;

	direction.x = cos(radians);
	direction.y = sin(radians);

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

/* t_point	ut_get_direction(double radians)
{
	t_point	direction;

	direction.x = cos(radians);
	direction.y = sin(radians);

	if (fabs(direction.x) < RADTOL)
		direction.x = 0;
	else if (direction.x < 0 - RADTOL)
		direction.x = -1;
	else
		direction.x = 1;
	
	if (fabs(direction.y) < RADTOL)
		direction.y = 0;
	else if (direction.y < 0 - RADTOL)
		direction.y = -1;
	else
		direction.y = 1;

	return (direction);
} */

/* t_point	ut_get_direction(double radians)
{
	t_point	direction;

	if ((radians < RAD_90 + RAD_TOL && radians > RAD_90 - RAD_TOL)
		|| (radians > RAD_270 - RAD_TOL && radians < RAD_270 + RAD_TOL))
		direction.x = 0;
	else if ((radians < RAD_90 - RAD_TOL && radians >= RAD_0)
		|| radians > RAD_270 + RAD_TOL && radians <= RAD_360)
		direction.x = 1;
	else
		direction.x = -1;
	if ((radians <= RAD_0 + RAD_TOL || radians >= RAD_360 + RAD_TOL)
		|| (radians < RAD_180 + RAD_TOL && radians > RAD_180 - RAD_TOL))
		direction.y = 0;
	else if (radians)
} */