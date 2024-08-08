#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"
#include "string.h"

bool	test_dm_load_colors(void)
{
	int	equal = 0;
	

	t_datamodel	test_model =
	{
		.floor_raw = "F 0,100,200\n",
		.ceiling_raw = "C 100,100,100\n"
	};

	t_datamodel	*real_model;
	t_list		*lines_list;

	real_model = scalloc(1, sizeof(t_datamodel));

	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("F 0,100,200\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("C 100,100,100\n")));

	dm_load_colors(real_model, lines_list);

	equal += strcmp(test_model.floor_raw, real_model->floor_raw);
	equal += strcmp(test_model.ceiling_raw, real_model->ceiling_raw);
	if (equal != 0)
	{
		printf(RED"Wrong color!\n"RES);
		return (false);
	}
	return (true);
}