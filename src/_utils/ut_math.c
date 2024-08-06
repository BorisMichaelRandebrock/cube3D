#include <math.h>
#include "float.h"

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

	if (fabs(_cos) < DBL_EPSILON)
		return (0);
	else if (fabs(_cos + 1) < DBL_EPSILON)
		return(-1);
	else if (fabs(_cos - 1) < DBL_EPSILON)
		return (1);
	return (_cos);
}

double	ut_sin(double angle)
{
	double	_sin = sin(angle);

	if (fabs(_sin) < DBL_EPSILON)
		return (0);
	else if (fabs(_sin + 1) < DBL_EPSILON)
		return(-1);
	else if (fabs(_sin - 1) < DBL_EPSILON)
		return (1);
	return (_sin);
}