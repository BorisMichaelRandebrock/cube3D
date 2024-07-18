#include "cube3d.h"

void	flood_fill(t_tilemap *game, size_t x, size_t y)
{
	if (x < 0 || y < 0 || x >= game->size.x|| y >= game->size.y
		|| game->tilemap[x][y] == 'V' || game->tilemap[x][y] == '1'
		|| game->tilemap[x][y] == 'E' || game->tilemap[x][y] == 'N'
		|| game->tilemap[x][y] == 'W' || game->tilemap[x][y] == 'S')
		return ;
	if (game->tilemap[x][y] == ' ')
		error_quit("Map is not closed");
	game->tilemap[x][y] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
