#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

static void	_check_rgb_range(int rgb)
{
	if (rgb > 255 || rgb < 0)
		error_quit("Wrong rbg range values.\n");
}

static int	_rgbtohex(char *buffer)
{
	int		hex_color;
	char	**split_values;
	int		lshift;
	int		i;
	int		tmp;

	tmp = 0;
	lshift = 24;
	split_values = ft_split(&buffer[2], ',');
	hex_color = 0;
	i = 0;
	while (split_values[i])
	{
		tmp = ft_atoi(split_values[i++]);
		_check_rgb_range(tmp);
		tmp <<= lshift;
		hex_color |= tmp;
		lshift -= 8;
	}
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
