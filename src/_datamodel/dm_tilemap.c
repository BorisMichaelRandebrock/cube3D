#include "cube3d.h"

void	dm_free_tilemap(t_tilemap *tilemap)
{
	int y;

	y = 0;
	while (y < tilemap->size.y)
		free(tilemap->map[y++]);
	free(tilemap);
}

t_tilemap	*dm_copy_tilemap_(t_tilemap *tilemap)
{
	int			y;
	t_tilemap	*_tilemap;

	_tilemap = ut_scalloc(1, sizeof(t_tilemap));
	_tilemap->size.x = tilemap->size.x;
	_tilemap->size.y = tilemap->size.y;
	_tilemap->map = ut_scalloc(_tilemap->size.y, sizeof(char *));
	y = 0;

	while (y < _tilemap->size.y)
	{
		_tilemap->map[y] = ft_strdup(tilemap->map[y]);
		y++;
	}
	return(_tilemap);
}