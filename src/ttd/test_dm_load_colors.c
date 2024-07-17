#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ansi.h"
#include "libft.h"
#include "cube3d.h"
#include "tests.h"
#include "respath.h"

static void _free_test(t_datamodel *dm)
{
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

bool	test_dm_load_colors(void)
{
	int	equal = 0;
	t_datamodel	test_model =
	{
		.floor_color = 0x0064C800,
		.ceiling_color = 0x64646400,
	};

	t_datamodel *real_model;
	int			fd;

	real_model = scalloc(1, sizeof(t_datamodel));
	fd = open(TEST_LEVEL0_PATH, O_RDONLY, 0777);
	_skip_cub_section(fd);
	dm_load_colors(real_model, fd);
	close(fd);
	
	equal += (test_model.ceiling_color - real_model->ceiling_color);
	equal += (test_model.floor_color - real_model->floor_color);
	_free_test(real_model);
	if (equal != 0)
	{
		printf(RED"Wrong color!\n"RES);
		return (false);
	}
	return (true);
}