#include "cube3d.h"

void	free_dm(t_datamodel *dm)
{
	t_datamodel *_dm;
	int	y;

	if (dm)
		_dm = dm;
	else
		_dm = get_dm(NULL);
	free(_dm->no_tex_path);
	free(_dm->so_tex_path);
	free(_dm->we_tex_path);
	free(_dm->ea_tex_path);
	y = 0;
	while (y < _dm->tilemap->size.y)
		free(_dm->tilemap->map[y++]);
	free(_dm->tilemap);
	free(_dm);
}

t_datamodel	*get_dm(t_datamodel *dm)
{
	static t_datamodel *datamodel = NULL;
	
	if (!datamodel && dm)
		datamodel = dm;
	return (datamodel);
}