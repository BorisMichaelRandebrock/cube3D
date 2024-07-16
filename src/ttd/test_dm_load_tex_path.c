#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"

static void _free_test(t_datamodel *dm)
{
	free(dm->no_tex_path);
	free(dm->so_tex_path);
	free(dm->we_tex_path);
	free(dm->ea_tex_path);
	free(dm);
}

bool	test_dm_load_tex_path(void)
{
	int	equal = 0;
	t_datamodel	test_model =
	{
		.no_tex_path = NO_TEX_PATH,
		.so_tex_path = SO_TEX_PATH,
		.we_tex_path = WE_TEX_PATH,
		.ea_tex_path = EA_TEX_PATH,
	};

	t_datamodel *real_model;
	int			fd;

	real_model = scalloc(1, sizeof(t_datamodel));
	fd = open(TEST_LEVEL0_PATH, O_RDONLY, 0777);
	dm_load_tex_path(real_model, fd);
	close(fd);
	
	equal += strcmp(test_model.no_tex_path, real_model->no_tex_path);
	equal += strcmp(test_model.so_tex_path, real_model->so_tex_path);
	equal += strcmp(test_model.we_tex_path, real_model->we_tex_path);
	equal += strcmp(test_model.ea_tex_path, real_model->ea_tex_path);
	_free_test(real_model);
	if (equal != 0)
	{
		printf(RED"%d - Wrong texture path!\n"RES, equal);
		printf("test_model: %s\n", test_model.no_tex_path);
		printf("real_model: %s\n", real_model->no_tex_path);
		return (false);
	}
	return (true);
}