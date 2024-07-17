#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

static void	_load_map_data_(t_datamodel *dm, t_list *row_list)
{
	t_list	*head;
	int		i;

	i = 0;
	dm->tilemap->map = scalloc(dm->tilemap->size.y, sizeof(char *));
	while (i < dm->tilemap->size.y)
	{
		head = row_list;
		((char *)head->content)[ft_strlen(head->content) - 1] = '\0';
		dm->tilemap->map[i++] = head->content;
		row_list = row_list->next;
		free(head);
	}
}

void	dm_load_tilemap_(t_datamodel *dm, int fd)
{
	char	buffer[BUFSIZ];
	t_list	*row_list;
	int		i;

	ft_memset(buffer, '\0', BUFSIZ);
	dm->tilemap = scalloc(1, sizeof(t_tilemap));
	row_list = NULL;
	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
		{
			ft_lstadd_back(&row_list, ft_lstnew(ft_strdup(buffer)));
			ft_memset(buffer, '\0', BUFSIZ);
			if (i > dm->tilemap->size.x)
				dm->tilemap->size.x = i;
			dm->tilemap->size.y++;
			i = 0;
			continue ;
		}
		i++;
	}
	_load_map_data_(dm, row_list);
}
