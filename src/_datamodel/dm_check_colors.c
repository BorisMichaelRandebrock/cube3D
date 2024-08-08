/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:20 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 17:34:21 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdbool.h>
#include <fcntl.h>

#define MAX_ALPHA 0x000000FF

static void	_check_rgb_range(int rgb)
{
	if (rgb > 255 || rgb < 0)
		ut_error_quit("Wrong rbg range values.\n");
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
	return (hex_color | MAX_ALPHA);
}

bool	dm_check_colors(t_datamodel *dm)
{
	dm->ceiling_raw[ft_strlen(dm->ceiling_raw) - 1] = '\0';
	dm->floor_raw[ft_strlen(dm->floor_raw) - 1] = '\0';
	if (*dm->floor_raw == '\0' || *dm->ceiling_raw == '\0')
		return (false);
	dm->ceiling_hex = _rgbtohex(dm->ceiling_raw);
	dm->floor_hex = _rgbtohex(dm->floor_raw);
	return (true);
}
