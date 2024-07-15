#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

t_datamodel	*load_cub(char *filename)
{
	t_datamodel	*dm;
	int			fd;
	char		buffer[BUFSIZ];

	dm = __calloc(1, sizeof(t_datamodel));
	get_dm(dm);
	ft_memset(buffer, '\0', BUFSIZ);
	fd = open(filename, O_RDONLY, 0777);
	dm_load_textures(dm, buffer, fd);
	dm_load_surfaces_color(dm, buffer, fd);
	dm_load_tilemap(dm, buffer, fd);
	close(fd);
	return (dm);
}

void	check_dm(void)
{
	t_datamodel *dm;
	dm = get_dm(NULL);


	dm_check_textures(dm);
}

