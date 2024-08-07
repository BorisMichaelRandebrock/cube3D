#include <math.h>
#include "cube3d.h"
#include "rad.h"

//TODO BORRRAR, no usar grados sexagesimales
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