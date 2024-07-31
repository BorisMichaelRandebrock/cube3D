#include "cube3d.h"

t_datamodel	*dm_get(t_datamodel *dm)
{
	static t_datamodel	*datamodel = NULL;

	if (!datamodel && dm)
		datamodel = dm;
	return (datamodel);
}
