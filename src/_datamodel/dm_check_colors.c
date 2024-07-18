#include "cube3d.h"
#include <stdbool.h>
#include <fcntl.h>


static void	_check_rgb_range(int rgb)
{
	if (rgb > 255 || rgb < 0)
		error_quit("Wrong rbg range values.\n");
}

static int	_rgbtohex(char *line)
{
	int		hex_color;
	char	**split_values;
	int		lshift;
	int		i;
	int		tmp;

	tmp = 0;
	lshift = 24;
	split_values = ft_split(&line[2], ',');
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

bool	dm_check_colors(t_datamodel *dm)
{
	dm->ceiling_raw[ft_strlen(dm->ceiling_raw) - 1] = '\0';
	dm->floor_raw[ft_strlen(dm->floor_raw) - 1] = '\0';
	dm->ceiling_hex = _rgbtohex(dm->ceiling_raw);
	dm->floor_hex = _rgbtohex(dm->floor_raw);
	if (dm->ceiling_hex < 0 || dm->floor_hex < 0)
		return (false);
	return (true);
}
