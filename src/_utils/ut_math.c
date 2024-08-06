#include <stdio.h>
#include <unistd.h>
#include "ansi.h"
#include "cube3d.h"
#include "libft.h"

double	ut_clamp(double min, double max, double num)
{
	if (num < min)
		return (min);
	else if (num > max)
		return (max);
	else
		return (num);
}