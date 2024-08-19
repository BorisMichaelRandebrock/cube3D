/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:32 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/19 11:44:21 by fmontser         ###   ########.fr       */
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

void	dm_graphics_init(t_datamodel *dm)
{
	dm->no_tex_path = ft_strdup("");
	dm->so_tex_path = ft_strdup("");
	dm->we_tex_path = ft_strdup("");
	dm->ea_tex_path = ft_strdup("");
	dm->floor_raw = ft_strdup("");
	dm->ceiling_raw = ft_strdup("");
}
