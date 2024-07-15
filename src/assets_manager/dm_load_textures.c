#include <stdio.h>
#include <unistd.h>
#include "cube3d.h"
#include "libft.h"

#define OFFSET 3

static char	*_load_textures_path(char *buffer)
{
	char	*path;

	path = ft_strdup(buffer);
	*(ft_strchr(path, '\n')) = '\0';
	return (path);
}

void	dm_load_textures(t_datamodel *dm, char *buffer, int fd)
{
	int	i;

	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
			break ;
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'N' && buffer[1] == 'O')
				dm->no_tex_path = _load_textures_path(&buffer[OFFSET]);
			if (buffer[0] == 'S' && buffer[1] == 'O')
				dm->so_tex_path = _load_textures_path(&buffer[OFFSET]);
			if (buffer[0] == 'W' && buffer[1] == 'E')
				dm->we_tex_path = _load_textures_path(&buffer[OFFSET]);
			if (buffer[0] == 'E' && buffer[1] == 'A')
				dm->ea_tex_path = _load_textures_path(&buffer[OFFSET]);
			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			continue ;
		}
		i++;
	}
	ft_memset(buffer, '\0', BUFSIZ);
}