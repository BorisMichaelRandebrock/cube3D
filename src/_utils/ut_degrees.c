#include <math.h>
#define M_PI 3.14159265358979323846

double	ut_deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	ut_rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	ut_rad_mirror(double radians)
{
	int	deg;

	deg = ut_rad_to_deg(radians);
	deg += 180;
	if (deg > 359)
		deg -= 360;
	return (ut_deg_to_rad(deg));
}