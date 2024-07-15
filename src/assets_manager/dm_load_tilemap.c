#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

static void	_load_map_data(t_datamodel *dm, t_list *row_list)
{
	t_list	*head;
	int		i;

	i = 0;
	dm->tilemap->map = __calloc(dm->tilemap->size.y,
			sizeof(char *));
	while (i < dm->tilemap->size.y)
	{
		head = row_list;
		dm->tilemap->map[i++] = head->content;
		row_list = row_list->next;
		free(head);
	}
}

void	dm_load_tilemap(t_datamodel *dm, char *buffer, int fd)
{
	char	*row;
	t_list	*row_list;
	int		i;

	dm->tilemap = __calloc(1, sizeof(t_tilemap));
	row_list = NULL;
	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
		{
			row = ft_strdup(buffer);
			row[ft_strlen(row) - 1] = '\0';
			ft_lstadd_back(&row_list, ft_lstnew(row));
			ft_memset(buffer, '\0', BUFSIZ);
			if (i > dm->tilemap->size.x)
				dm->tilemap->size.x = i;
			dm->tilemap->size.y++;
			i = 0;
			continue ;
		}
		i++;
	}
	_load_map_data(dm, row_list);
}