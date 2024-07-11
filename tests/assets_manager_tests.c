#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "cube3d.h"

/*
if map_file  exists
if map is correct (walls)
if map is correct (correct characters -> N, S, W, E, 0, 1,
(Space is  allowed but only if surrounded by 1)))
if map is correct (height or width is not superior to MAX_INT)
if map is correct (colors are defined)
if map is correct (colors are defined in rgb)
there are at least 4 textures (NO, EA, SO, WE)
textures are defined
 */

bool	load_cub_test(void)
{
	t_tilemap tilemap;
	tilemap.size.x = 5;
	tilemap.size.y = 3;
	char map[3][5] = {
		{'1','1','1','1','1'},
		{'1','0','N','0','1'},
		{'1','1','1','1','1'}
	};

	tilemap.map = (char **)map;

	t_datamodel	ex_model =
	{
		.no_tex_path = "../res/north_texture.png",
		.so_tex_path = "../res/south_texture.png",
		.we_tex_path = "../res/west_texture.png",
		.ea_tex_path = "../res/east_texture.png",
		.floor_color = 0x0064C800,
		.ceiling_color = 0x64646400,
		.tilemap = &tilemap
	};

	t_datamodel *test_model = load_cub("res/level_test.cub");

	//Comparacion de datamodels
	int	equal = 0;
	equal += strcmp(ex_model.no_tex_path, test_model->no_tex_path);
	equal += strcmp(ex_model.so_tex_path, test_model->so_tex_path);
	equal += strcmp(ex_model.we_tex_path, test_model->we_tex_path);
	equal += strcmp(ex_model.ea_tex_path, test_model->ea_tex_path);

	if (equal != 0)
	{
		printf(RED"%d - Wrong texture path!\n"RES, equal);
		printf("ex: %s\n", ex_model.no_tex_path);
		printf("test: %s\n", test_model->no_tex_path);
		return (false);
	}
	equal += (ex_model.ceiling_color - test_model->ceiling_color);
	equal += (ex_model.floor_color - test_model->floor_color);
	printf("col ex %d\n", ex_model.ceiling_color);
	printf("col ex %d\n", test_model->ceiling_color);
	if (equal != 0)
	{
		printf(RED"Wrong color!\n"RES);
		return (false);
	}

	if (equal != 0)
		return (false);

	int	x = 0;
	int y = 0;

	equal += (ex_model.tilemap->size.x - test_model->tilemap->size.x);
	equal += (ex_model.tilemap->size.y - test_model->tilemap->size.y);
	if (equal != 0)
	{
		printf(RED"Map wrong size! ex(%d,%d) vs test(%d,%d)\n"RES,
			ex_model.tilemap->size.y,ex_model.tilemap->size.x,
			test_model->tilemap->size.y,test_model->tilemap->size.x);
		return (false);
	}

	while (y < ex_model.tilemap->size.y)
	{
		while (x < ex_model.tilemap->size.x)
		{
			if (ex_model.tilemap->map[y][x] != test_model->tilemap->map[y][x])
			{
				printf(RED"Map wrong value at (%d,%d), value is %d\n"RES,
					y,x,test_model->tilemap->map[y][x]);
				return (false);
			}
			x++;
		}
		y++;
	}

}

int	main(void)
{
	load_cub_test();
	return (0);
}
