#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"

bool	test_dm_load_colors(void)
{
	int	equal = 0;
	t_datamodel	test_model =
	{
		.floor_color = 0x0064C800,
		.ceiling_color = 0x64646400,
	};

	t_datamodel	*real_model;
	t_list		*lines_list;

	real_model = scalloc(1, sizeof(t_datamodel));

	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("F 0,100,200\n")));
	ft_lstadd_back(&lines_list, ft_lstnew(ft_strdup("C 100,100,100\n")));

	dm_load_colors(real_model, lines_list);

	equal += (test_model.ceiling_color - real_model->ceiling_color);
	equal += (test_model.floor_color - real_model->floor_color);
	if (equal != 0)
	{
		printf(RED"Wrong color!\n"RES);
		return (false);
	}
	return (true);
}