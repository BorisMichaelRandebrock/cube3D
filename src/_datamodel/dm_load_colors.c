#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

//TODO y si faltan o sobran valores rgb en el cub?
//TODO y si hay valores rgb invalidos?

static int	_rgbtohex(char *buffer)
{
	int		hex_color;
	char	*rgb;
	char	**split_values;
	int		temp;
	int		i;

	rgb = ft_strdup(&buffer[2]);
	split_values = ft_split(rgb, ',');
	hex_color = 0;
	temp = ft_atoi(split_values[0]);
	temp <<= 24;
	hex_color |= temp;
	temp = ft_atoi(split_values[1]);
	temp <<= 16;
	hex_color |= temp;
	temp = ft_atoi(split_values[2]);
	temp <<= 8;
	hex_color |= temp;
	free(rgb);
	i = 0;
	while (split_values[i])
		free(split_values[i++]);
	free(split_values);
	return (hex_color);
}

void	dm_load_colors(t_datamodel *dm, int fd)
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
			if (buffer[0] == 'F' || buffer[0] == 'C')
			{
				if (buffer[0] == 'F')
					dm->floor_color = _rgbtohex(buffer);
				else if (buffer[0] == 'C')
					dm->ceiling_color = _rgbtohex(buffer);
			}
			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			continue ;
		}
		i++;
	}
}
