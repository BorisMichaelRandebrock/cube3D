#include "libft.h"
#include "cube3d.h"

void	free_tilemap(t_tilemap *tilemap)
{
	int y;

	y = 0;
	while (y < tilemap->size.y)
		free(tilemap->tilemap[y++]);
	free(tilemap);
}

t_tilemap	*copy_tilemap_(t_tilemap *tilemap)
{
	int			y;
	t_tilemap	*_tilemap;

	_tilemap = scalloc(1, sizeof(t_tilemap));
	_tilemap->size.x = tilemap->size.x;
	_tilemap->size.y = tilemap->size.y;
	_tilemap->tilemap = scalloc(_tilemap->size.y, sizeof(char *));
	y = 0;

	while (y < _tilemap->size.y)
	{
		_tilemap->tilemap[y] = ft_strdup(tilemap->tilemap[y]);
		y++;
	}
	return(_tilemap);
}