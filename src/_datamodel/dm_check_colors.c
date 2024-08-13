/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:20 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 17:42:00 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <fcntl.h>

#define MAX_ALPHA 0x000000FF

static void	_check_rgb_range(int rgb)
{
	if (rgb > 255 || rgb < 0)
		ut_error_quit("Wrong rbg range values.\n");
}

static void _validate_rgb(char **split_values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(split_values[i])
	{
		while(split_values[i][j])
		{
			if (!ft_isdigit(split_values[i][j]))
				ut_error_quit("Wrong rgb values\n");
			j++;
		}
		j = 0;
		i++;
	}
	if (i != 3)
		ut_error_quit("Wrong rgb values\n");
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
	_validate_rgb(split_values);
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
	return (hex_color | MAX_ALPHA);
}

bool	dm_check_colors(t_datamodel *dm)
{
	dm->ceiling_raw[ft_strlen(dm->ceiling_raw) - 1] = '\0';
	dm->floor_raw[ft_strlen(dm->floor_raw) - 1] = '\0';
	if (dm->floor_raw[0] == '\0' || dm->floor_raw[1] != ' '
		|| dm->ceiling_raw[0] == '\0' || dm->ceiling_raw[1] != ' ')
		return (false);
	dm->ceiling_hex = _rgbtohex(dm->ceiling_raw);
	dm->floor_hex = _rgbtohex(dm->floor_raw);
	return (true);
}
