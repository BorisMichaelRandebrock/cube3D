#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"

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
	t_list		*lines_list = NULL;

	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("NO res/north_texture.png\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("SO res/south_texture.png\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("WE res/west_texture.png\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("EA res/east_texture.png\n")));

	real_model = scalloc(1, sizeof(t_datamodel));

	dm_load_tex_path(real_model, lines_list);
	
	equal += strcmp(test_model.no_tex_path, real_model->no_tex_path);
	equal += strcmp(test_model.so_tex_path, real_model->so_tex_path);
	equal += strcmp(test_model.we_tex_path, real_model->we_tex_path);
	equal += strcmp(test_model.ea_tex_path, real_model->ea_tex_path);
	if (equal != 0)
	{
		printf(RED"%d - Wrong texture path!\n"RES, equal);
		printf("test_model: %s\n", test_model.no_tex_path);
		printf("real_model: %s\n", real_model->no_tex_path);
		return (false);
	}

	ft_lstclear(&lines_list, free);
	return (true);
}