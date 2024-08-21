/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:32 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/21 17:58:50 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_datamodel	*dm_get(t_datamodel *dm)
{
	static t_datamodel	*datamodel = NULL;

	if (!datamodel && dm)
		datamodel = dm;
	return (datamodel);
}

void	dm_seal_map(t_datamodel *dm)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	while (y < dm->tilemap->size.y)
	{
		while (x < dm->tilemap->size.x)
		{
			c = dm->tilemap->map[y][x];
			if (c != 'N' && c != 'S' && c != 'W'
				&& c != 'E' && c != '0' && c != '1')
				dm->tilemap->map[y][x] = '1';
			x++;
		}
		x = 0;
		y++;
	}
}

t_list	*dm_parse_lines(t_datamodel *dm, t_list *next_lines)
{
	char	*line;

	while (next_lines)
	{
		line = next_lines->content;
		if ((line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A'))
		{
			next_lines = dm_load_tex_path(dm, next_lines);
			continue ;
		}
		else if (line[0] == 'C' || line[0] == 'F')
		{
			next_lines = dm_load_colors(dm, next_lines);
			continue ;
		}
		else if (line[0] == '1' || line[0] == ' ')
			break ;
		next_lines = next_lines->next;
	}
	return (next_lines);
}

void	dm_graphics_init(t_datamodel *dm)
{
	dm->no_tex_path = ft_strdup("");
	dm->so_tex_path = ft_strdup("");
	dm->we_tex_path = ft_strdup("");
	dm->ea_tex_path = ft_strdup("");
	dm->floor_raw = ft_strdup("");
	dm->ceiling_raw = ft_strdup("");
}
