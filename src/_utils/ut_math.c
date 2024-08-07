#include <math.h>
#include "rad.h"

#define EPSILON 0.000001

double	ut_clamp(double min, double max, double num)
{
	if (num < min)
		return (min);
	else if (num > max)
		return (max);
	else
		return (num);
}
double	ut_cos(double angle)
{
	double	_cos = cos(angle);

	if (fabs(_cos) < EPSILON)
		return (0);
	else if (fabs(_cos + 1) < EPSILON)
		return(-1);
	else if (fabs(_cos - 1) < EPSILON)
		return (1);
	return (_cos);
}

double	ut_sin(double angle)
{
	double	_sin = sin(angle);

	if (fabs(_sin) < EPSILON)
		return (0);
	else if (fabs(_sin + 1) < EPSILON)
		return(-1);
	else if (fabs(_sin - 1) < EPSILON)
		return (1);
	return (_sin);
}

double ut_norm_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
