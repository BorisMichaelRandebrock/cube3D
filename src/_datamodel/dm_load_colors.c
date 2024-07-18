#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"

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

t_list	*dm_load_colors(t_datamodel *dm, t_list *next_lines)
{
	char	*line;
	t_list	*end_line;

	dm->floor_color = -1;
	dm->ceiling_color = -1;
	while (next_lines)
	{
		line = next_lines->content;
		if (line[0] == 'F')
		{
			dm->floor_color = _rgbtohex(line);
			end_line = next_lines;
		}
		else if (line[0] == 'C')
		{
			dm->ceiling_color = _rgbtohex(line);
			end_line = next_lines;
		}
		next_lines = next_lines->next;
	}
	return (end_line->next);
}
