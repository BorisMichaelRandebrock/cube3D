#include <stdio.h>
#include <unistd.h>
#include "ansi.h"
#include "cube3d.h"
#include "libft.h"

float	ut_abs(float num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

float	ut_clamp(float min, float max, float num)
{
	if (num < min)
		return (min);
	else if (num > max)
		return (max);
	else
		return (num);
}