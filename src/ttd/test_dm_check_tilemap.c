#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

void	test_dm_check_tilemap()
{
	t_tilemap	*tilemap = scalloc(1, sizeof(t_tilemap));
	t_datamodel	*dm = scalloc(1, sizeof(t_datamodel));

	dm->tilemap = tilemap;
	tilemap->size.y = 3;
	tilemap->size.x = 6;
	tilemap->tilemap


	//dm_check_tilemap();
}
