#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

//TODO comprobar y conseguir puto de entrada && contador Highlander 
// copy mapa previo

static bool _check_flood_fill(t_tilemap *tilemap)
{
	int		x;
	int		y;


	if (x < 0 || y < 0 || x >= tilemap->size.x|| y >= tilemap->size.y
		|| tilemap->map[x][y] == 'V' || tilemap->map[x][y] == '1'
		|| tilemap->map[x][y] == 'E' || tilemap->map[x][y] == 'N'
		|| tilemap->map[x][y] == 'W' || tilemap->map[x][y] == 'S')
			;
	else (tilemap->map[x][y] == ' ')
		error_quit("Map is not closed");
	tilemap->map[x][y] = 'V';
	flood_fill(tilemap, x + 1, y);
	flood_fill(tilemap, x - 1, y);
	flood_fill(tilemap, x, y + 1);
	flood_fill(tilemap, x, y - 1);
}

static bool	_is_invalid(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E' && c != ' ')
		return (true);
	return (false);
}

static bool _check_map_chars(t_tilemap *tilemap)
{
	int		x;
	int		y;
	int		line_size;
	
	x = 0;
	y = 0;
	
	while (y < tilemap->size.y)
	{	
		line_size = ft_strlen(tilemap->map[y]);	
		while (x < line_size)
		{
			if (_is_invalid(tilemap->map[y][x]))
				return (false);
			x++;				
		}
		x = 0;
		y++;
	}
	return (true);
}

bool	dm_check_tilemap(t_datamodel *dm)
{
	if (!_check_map_chars(dm->tilemap))
		return (false);


	if (_check_flood_fill(dm->tilemap))
	return (true);
}
