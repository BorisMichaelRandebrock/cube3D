#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"


bool	test_dm_load_tilemap(void)
{
	int	equal = 0;
	int	i = 0;
	int	x = 0;
	int y = 0;
	t_tilemap tilemap;

	tilemap.size.x = 6;
	tilemap.size.y = 3;
	char map[3][6] = {
		{' ','1','1','1','1','1'},
		{' ','1','0','N','0','1'},
		{' ','1','1','1','1','1'}
	};
	
	tilemap.map = (char **)calloc(tilemap.size.y, sizeof(char *));
	while( i < tilemap.size.y)
	{
		tilemap.map[i] = (char *)calloc(tilemap.size.x, sizeof(char));
		memcpy(tilemap.map[i], map[i], tilemap.size.x);
		i++;
	}

	t_datamodel	test_model =
	{
		.tilemap = &tilemap
	};

	t_datamodel real_model =
	{
		.tilemap = NULL
	};

	t_list	*lines_list = NULL;
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup(" 11111\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup(" 10N01\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup(" 11111\n")));

	dm_load_tilemap_(&real_model, lines_list);


	//MAP SIZE DIFF TEST
	equal += (test_model.tilemap->size.x - real_model.tilemap->size.x);
	equal += (test_model.tilemap->size.y - real_model.tilemap->size.y);
	if (equal != 0)
	{
		printf(RED"Map wrong size! test(%d,%d) vs real(%d,%d)\n"RES,
			test_model.tilemap->size.y,test_model.tilemap->size.x,
			real_model.tilemap->size.y,real_model.tilemap->size.x);
		return (false);
	}

	//MAP DATA DIFF TEST
	while (y < test_model.tilemap->size.y)
	{
		while (x < test_model.tilemap->size.x)
		{
			if (test_model.tilemap->map[y][x] != real_model.tilemap->map[y][x])
			{

				printf(RED"Map wrong value at (%d,%d), value is '%c' and must be '%c'\n"RES,
					y,x,real_model.tilemap->map[y][x], test_model.tilemap->map[y][x]);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}