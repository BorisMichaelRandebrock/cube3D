#include "cube3d.h"
#include <stdbool.h>
#include <fcntl.h>

bool	dm_check_tex_files(t_datamodel *dm)
{
	if (open(dm->no_tex_path, O_RDONLY, 0777) != 0)
		return (true);
	return (false);
}
