#include "cube3d.h"
#include <stdbool.h>
#include <fcntl.h>

bool	dm_check_colors(t_datamodel *dm)
{
	if (dm->ceiling_color < 0 || dm->floor_color < 0)
		return (false);
	return (true);
}
