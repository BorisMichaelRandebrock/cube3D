#include "cube3d.h"

void	flood_fill(t_tilemap *game, size_t x, size_t y)
{
	if (x < 0 || y < 0 || x >= game->size.x|| y >= game->size.y
		|| game->map[x][y] == 'V' || game->map[x][y] == '1'
		|| game->map[x][y] == 'E' || game->map[x][y] == 'N'
		|| game->map[x][y] == 'W' || game->map[x][y] == 'S')
		return ;
	if (game->map[x][y] == ' ')
		exit(perror("Map is not closed"));
	game->map[x][y] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
