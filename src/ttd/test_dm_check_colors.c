#include <stdbool.h>
#include "respath.h"
#include "cube3d.h"

bool	test_dm_check_colors(void)
{
	t_datamodel dm =
	{
		.ceiling_color = -1,
		.floor_color = -1
	};
	if (dm_check_colors(&dm))
		return (false);
	
	dm.floor_color = 0x00000000;
	dm.ceiling_color = 0xFFFFFF00;
	if (dm_check_colors(&dm))
		return (false);
	
	return (true);
}