#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

static void	_load_map_data_(t_datamodel *dm, t_list *next_lines)
{
	int		i;
	int		x_size;

	i = 0;
	dm->tilemap->tilemap = scalloc(dm->tilemap->size.y, sizeof(char *));
	while (i < dm->tilemap->size.y)
	{
		((char *)next_lines->content)[ft_strlen(next_lines->content) - 1] = '\0';
		x_size = ft_strlen(next_lines->content);
		if (x_size > dm->tilemap->size.x)
			dm->tilemap->size.x = (x_size);
		dm->tilemap->tilemap[i++] = ft_strdup(next_lines->content);
		next_lines = next_lines->next;
	}
}

void	dm_load_tilemap_(t_datamodel *dm, t_list *next_lines)
{
	t_list	*lines_list;

	lines_list = next_lines;
	dm->tilemap = scalloc(1, sizeof(t_tilemap));
	while (lines_list)
	{
		dm->tilemap->size.y++;
		lines_list = lines_list->next;
	}
	_load_map_data_(dm, next_lines);
}
