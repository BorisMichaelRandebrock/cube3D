/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_check_tilemap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:33:38 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"
#include "libft.h"

static	t_rect	_get_player_position(t_tilemap *tilemap)
{
	int		line_size;
	t_rect	player_pos;
	char	c;

	player_pos.x = 0;
	player_pos.y = 0;
	while (player_pos.y < tilemap->size.y)
	{
		line_size = ft_strlen(tilemap->map[player_pos.y]);
		while (player_pos.x < line_size)
		{
			c = tilemap->map[player_pos.y][player_pos.x];
			if (ft_strchr("NSWE", c))
				return (player_pos);
			player_pos.x++;
		}
		player_pos.x = 0;
		player_pos.y++;
	}
	ut_error_quit("Player not found.. please try again\n");
	return (player_pos);
}

static bool	_check_flood_fill(t_tilemap *tilemap, int x, int y)
{
	int	line_size;

	if (y == -1 || y >= tilemap->size.y)
		ut_error_quit("Wrong tilemappppppp\n");
	line_size = ft_strlen(tilemap->map[y]);
	if (x < 0 || y < 0 || x >= line_size || y >= tilemap->size.y)
		return (false);
	if (!ft_strchr("NSWE10_", tilemap->map[y][x]))
		return (false);
	if (ft_strchr("1_", tilemap->map[y][x]))
		return (true);
	tilemap->map[y][x] = '_';
	if (!_check_flood_fill(tilemap, x + 1, y))
		return (false);
	if (!_check_flood_fill(tilemap, x - 1, y))
		return (false);
	if (!_check_flood_fill(tilemap, x, y + 1))
		return (false);
	if (!_check_flood_fill(tilemap, x, y - 1))
		return (false);
	return (true);
}

static	bool	_set_spawn(t_tilemap *tilemap, char c, int x, int y)
{
	tilemap->spawn_point.x = x;
	tilemap->spawn_point.y = y;
	tilemap->spawn_char = c;
	return (true);
}

static bool	_check_map_chars(t_tilemap *tilemap)
{
	int		x;
	int		y;
	char	c;
	bool	ok_flag;
	int		line_size;

	x = 0;
	y = 0;
	ok_flag = false;
	while (y < tilemap->size.y)
	{
		line_size = ft_strlen(tilemap->map[y]);
		while (x < line_size)
		{
			c = tilemap->map[y][x];
			if ((ft_strchr("NSWE", c) && ok_flag) || (!ft_strchr("NSWE01 ", c)))
				return (false);
			if (ft_strchr("NSWE", c))
				ok_flag = _set_spawn(tilemap, c, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (ok_flag);
}

bool	dm_check_tilemap(t_datamodel *dm)
{
	t_rect		position;
	t_tilemap	*map_copy;

	map_copy = dm_copy_tilemap_(dm->tilemap);
	position = _get_player_position(dm->tilemap);
	if (!_check_map_chars(dm->tilemap))
		return (false);
	if (!_check_flood_fill(map_copy, position.x, position.y))
	{
		dm_free_tilemap(map_copy);
		return (false);
	}
	dm_free_tilemap(map_copy);
	return (true);
}
