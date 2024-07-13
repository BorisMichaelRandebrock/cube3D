#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "cube3d.h"

/* 
if map_file  exists
if map is correct (walls)
if map is correct (correct characters -> N, S, W, E, 0, 1, (Space is  allowed but only if surrounded by 1)))
if map is correct (height or width is not superior to MAX_INT)
if map is correct (colors are defined)
if map is correct (colors are defined in rgb)
there are at least 4 textures (NO, EA, SO, WE)
textures are defined 
 */


static void	free_test(t_tilemap *tilemap)
{
	int y = 0;

	while(y < tilemap->size.y)
		free(tilemap->map[y++]);
	free(tilemap->map);
}

bool	load_cub_test(void)
{
	int	equal = 0;
	int	i = 0;
	int	x = 0;
	int y = 0;
	t_tilemap tilemap;

	//TEST 0 DATA
	tilemap.size.x = 6;
	tilemap.size.y = 3;

	char map[3][6] = {
		{' ','1','1','1','1','1'},
		{' ','1','0','N','0','1'},
		{' ','1','1','1','1','1'}
	};
	
	tilemap.map = ft_calloc(tilemap.size.y, sizeof(char *));
	while( i < tilemap.size.y)
	{
		tilemap.map[i] = ft_calloc(tilemap.size.x, sizeof(char));
		memcpy(tilemap.map[i], map[i], tilemap.size.x);
		i++;
	}

	t_datamodel	test_model =
	{
		.no_tex_path = "../res/north_texture.png",
		.so_tex_path = "../res/south_texture.png",
		.we_tex_path = "../res/west_texture.png",
		.ea_tex_path = "../res/east_texture.png",
		.floor_color = 0x0064C800,
		.ceiling_color = 0x64646400,
		.tilemap = &tilemap
	};

	//DIFF TESTS

	t_datamodel *real_model = load_cub("../res/level_test.cub");
	
	//TEXTURE PATH DIFF TEST
	equal += strcmp(test_model.no_tex_path, real_model->no_tex_path);
	equal += strcmp(test_model.so_tex_path, real_model->so_tex_path);
	equal += strcmp(test_model.we_tex_path, real_model->we_tex_path);
	equal += strcmp(test_model.ea_tex_path, real_model->ea_tex_path);
	if (equal != 0)
	{
		printf("%d - Wrong texture path!\n", equal);
		printf("ex: %s\n", test_model.no_tex_path);
		printf("test: %s\n", real_model->no_tex_path);
		free_test(&tilemap);
		return (false);
	}

	//FLOOR CEILING COLOR DIFF TEST
	equal += (test_model.ceiling_color - real_model->ceiling_color);
	equal += (test_model.floor_color - real_model->floor_color);
	if (equal != 0)
	{
		printf("Wrong color!\n");
		free_test(&tilemap);
		return (false);
	}

	//MAP SIZE DIFF TEST

	equal += (test_model.tilemap->size.x - real_model->tilemap->size.x);
	equal += (test_model.tilemap->size.y - real_model->tilemap->size.y);
	if (equal != 0)
	{
		printf("Map wrong size! test(%d,%d) vs real(%d,%d)\n",
			test_model.tilemap->size.y,test_model.tilemap->size.x,
			real_model->tilemap->size.y,real_model->tilemap->size.x);
		free_test(&tilemap);
		return (false);
	}


	//MAP DATA DIFF TEST
	while (y < test_model.tilemap->size.y)
	{
		while (x < test_model.tilemap->size.x)
		{
			if (test_model.tilemap->map[y][x] != real_model->tilemap->map[y][x])
			{
				printf("Map wrong value at (%d,%d), value is '%c' and must be '%c'\n",
					y,x,real_model->tilemap->map[y][x], test_model.tilemap->map[y][x]);
				free_test(&tilemap);
				return (false);
			}
			x++;
		}
		y++;
	}
	free_test(&tilemap);
	return (true);
}

