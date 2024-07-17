#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"

static void	_free_test(t_datamodel *dm, t_tilemap *tilemap)
{
	int y = 0;

	while(y < tilemap->size.y)
		free(tilemap->map[y++]);
	free(tilemap->map);

	y = 0;
	while(y < dm->tilemap->size.y)
		free(dm->tilemap->map[y++]);
	free(dm->tilemap->map);
	free(dm->tilemap);
	free(dm);
}

static void _skip_cub_section(int fd)
{
	char	buffer[BUFSIZ];
	int		i;

	ft_memset(buffer, '\0', BUFSIZ);
	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
			break ;
		if (buffer[i] == '\n')
		{
			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			continue ;
		}
		i++;
	}
}

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

	t_datamodel *real_model;
	int			fd;

	real_model = scalloc(1, sizeof(t_datamodel));
	fd = open(TEST_LEVEL0_PATH, O_RDONLY, 0777);
	_skip_cub_section(fd);
	_skip_cub_section(fd);
	dm_load_tilemap_(real_model, fd);
	close(fd);

	//MAP SIZE DIFF TEST
	equal += (test_model.tilemap->size.x - real_model->tilemap->size.x);
	equal += (test_model.tilemap->size.y - real_model->tilemap->size.y);
	if (equal != 0)
	{
		printf(RED"Map wrong size! test(%d,%d) vs real(%d,%d)\n"RES,
			test_model.tilemap->size.y,test_model.tilemap->size.x,
			real_model->tilemap->size.y,real_model->tilemap->size.x);
		_free_test(real_model,&tilemap);
		return (false);
	}

	//MAP DATA DIFF TEST
	while (y < test_model.tilemap->size.y)
	{
		while (x < test_model.tilemap->size.x)
		{
			if (test_model.tilemap->map[y][x] != real_model->tilemap->map[y][x])
			{

				printf(RED"Map wrong value at (%d,%d), value is '%c' and must be '%c'\n"RES,
					y,x,real_model->tilemap->map[y][x], test_model.tilemap->map[y][x]);
				_free_test(real_model,&tilemap);
				return (false);
			}
			x++;
		}
		y++;
	}
	_free_test(real_model, &tilemap);
	return (true);
}