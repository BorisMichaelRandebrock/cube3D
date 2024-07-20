#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"
#include "string.h"
#include "ansi.h"

bool	test_dm_check_tilemap()
{
	t_tilemap	*tilemap = scalloc(1, sizeof(t_tilemap));
	t_datamodel	*dm = scalloc(1, sizeof(t_datamodel));
	char map[3][6] = 
	{
		{' ','1','1','1','1','1'},
		{' ','1','0','N','0','1'},
		{' ','1','1','1','1','1'}
	};
	int i = 0;
	tilemap->size.y = 3;
	tilemap->size.x = 6;
	tilemap->map = (char **)calloc(tilemap->size.y, sizeof(char *));
	while( i < tilemap->size.y)
	{
		tilemap->map[i] = (char *)calloc(tilemap->size.x, sizeof(char));
		memcpy(tilemap->map[i], map[i], tilemap->size.x);
		i++;
	}
	dm->tilemap = tilemap;

	//TESTS
	if (!dm_check_tilemap(dm))
		return (false);

	dm->tilemap->map[1][2] = 'X';
	if (dm_check_tilemap(dm))
		return (false);
	
	return (true);
		
}
