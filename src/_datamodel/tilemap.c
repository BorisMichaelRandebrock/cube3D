#include "cube3d.h"

t_rect	dm_get_spawn_point(t_tilemap *tilemap)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	x = 0;
	while (y < tilemap->size.y)
	{
		line = tilemap->map[y][x];
		while (x < ft_strlen(line))
		{

			x++;
		}
		y++;
	}
}

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

	_tilemap = scalloc(1, sizeof(t_tilemap));
	_tilemap->size.x = tilemap->size.x;
	_tilemap->size.y = tilemap->size.y;
	_tilemap->map = scalloc(_tilemap->size.y, sizeof(char *));
	y = 0;

	while (y < _tilemap->size.y)
	{
		_tilemap->map[y] = ft_strdup(tilemap->map[y]);
		y++;
	}
	return(_tilemap);
}