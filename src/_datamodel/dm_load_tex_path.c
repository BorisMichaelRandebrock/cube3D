#include <stdio.h>
#include <unistd.h>
#include "cube3d.h"
#include "libft.h"

#define PATH_OFFSET 3

static char	*_trim_path(char *buffer)
{
	char	*path;

	path = ft_strdup(buffer);
	*(ft_strchr(path, '\n')) = '\0';
	return (path);
}

void	dm_load_tex_path(t_datamodel *dm, char	*cub_file)
{
	char	buffer[BUFSIZ];
	int		i;

	ft_memset(buffer, '\0', BUFSIZ);
	i = 0;
	while (*cub_file)
	{
		buffer[i] = *cub_file;
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'N' && buffer[1] == 'O')
				dm->no_tex_path = _trim_path(&buffer[PATH_OFFSET]);
			if (buffer[0] == 'S' && buffer[1] == 'O')
				dm->so_tex_path = _trim_path(&buffer[PATH_OFFSET]);
			if (buffer[0] == 'W' && buffer[1] == 'E')
				dm->we_tex_path = _trim_path(&buffer[PATH_OFFSET]);
			if (buffer[0] == 'E' && buffer[1] == 'A')
				dm->ea_tex_path = _trim_path(&buffer[PATH_OFFSET]);
			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			cub_file++;
			continue ;
		}
		cub_file++;
		i++;
	}
}
