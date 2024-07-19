#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

//TODO comprobar y conseguir puto de entrada && contador Highlander 
// copy mapa previo
static bool	_find_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' )
		return (true);
	return (false);
}


static	t_rect	_get_player_position(t_tilemap *tilemap)
{
	int		line_size;
	t_rect	player_pos;

	player_pos.x = 0;
	player_pos.y = 0;	
	while (player_pos.y < tilemap->size.y)
	{	
		line_size = ft_strlen(tilemap->map[player_pos.y]);	
		while (player_pos.x < line_size)
		{
			if (_find_player(tilemap->map[player_pos.y][player_pos.x]))
				return (player_pos);
			player_pos.x++;				
		}
		player_pos.x = 0;
		player_pos.y++;
	}
	error_quit("Player not found.. please try again\n");
	return (player_pos);	
}

static bool	_is_invalid(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E' && c != ' ')
		return (true);
	return (false);
}

static bool _check_flood_fill(t_tilemap *tilemap, int x, int y)
{
	char c = tilemap->map[x][y];
	(void)c;
	if (x < 0 || y < 0 || x >= tilemap->size.x|| y >= tilemap->size.y
		|| tilemap->map[x][y] == '*' || tilemap->map[x][y] == '1')
			return (true);
	else if	(_is_invalid(tilemap->map[x][y]))
		return (false);
	tilemap->map[x][y] = '*';
	if (!_check_flood_fill(tilemap, x + 1, y))
		return (false);
	if(_check_flood_fill(tilemap, x - 1, y))
		return (false);
	if(_check_flood_fill(tilemap, x, y + 1))
		return (false);
	if(_check_flood_fill(tilemap, x, y - 1))
		return (false);
	return (true);
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
	t_rect	position;
	t_tilemap	*map_copy;

	map_copy = dm_copy_tilemap_(dm->tilemap);
	position = _get_player_position(dm->tilemap);
	if (!_check_map_chars(dm->tilemap))
		return (false);
	int		y = 0;
	while (y < dm->tilemap->size.y)
		printf("%s\n", dm->tilemap->map[y++]);
	printf("\n\n-----------------------------------------\n\n");
	if (!_check_flood_fill(map_copy, position.x, position.y))
	{
		y = 0;
		while (y < map_copy->size.y)
			printf("%s\n", map_copy->map[y++]);
		dm_free_tilemap(map_copy);
		return (false);
	}
	dm_free_tilemap(map_copy);
	return (true);
}




/* 		|| tilemap->map[x][y] == 'E' || tilemap->map[x][y] == 'N'
		|| tilemap->map[x][y] == 'W' || tilemap->map[x][y] == 'S' */

