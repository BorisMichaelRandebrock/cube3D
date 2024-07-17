#include <stdbool.h>
#include "respath.h"
#include "cube3d.h"

bool	test_dm_check_tex_files(void)
{
	t_datamodel dm =
	{
		.no_tex_path = NO_TEX_PATH,
		.ea_tex_path = EA_TEX_PATH
	};
	if (dm_check_tex_files(&dm))
		return (true);
	return (false);
}