#include <stdbool.h>
#include "respath.h"
#include "cube3d.h"

bool	test_dm_check_colors(void)
{
	bool	result = false;

	t_datamodel dm =
	{
		.ceiling_raw = ft_strdup("C 100,100,100\n"),
		.ceiling_hex = -1,
		.floor_raw = ft_strdup("F 0,100,200\n"),
		.floor_hex = -1
	};
	dm_check_colors(&dm);
	if (dm.ceiling_hex == 0x64646400 && dm.floor_hex == 0x0064C800)
		result = true;
	free(dm.ceiling_raw);
	free(dm.floor_raw);
	return (result);
}