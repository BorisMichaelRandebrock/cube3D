/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_tilemap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:40 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/21 17:54:44 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"
#include "libft.h"

static void	_clean_endline(char *line)
{
	char	c;
	int		line_end;

	line_end = ft_strlen(line) - 1;
	c = line[line_end];
	if (c == '\n')
		line[line_end] = '\0';
}

static void	_load_map_data_(t_datamodel *dm, t_list *next_lines)
{
	int		i;
	int		x_size;
	t_list	*line_count;

	line_count = next_lines;
	i = 0;
	while (i++ < dm->tilemap->size.y)
	{
		x_size = ft_strlen(line_count->content);
		if (x_size > dm->tilemap->size.x)
			dm->tilemap->size.x = x_size;
		line_count = line_count->next;
	}
	dm->tilemap->map = ut_scalloc(dm->tilemap->size.y, sizeof(char *));
	i = 0;
	while (i < dm->tilemap->size.y)
	{
		dm->tilemap->map[i] = ut_scalloc(dm->tilemap->size.x, sizeof(char));
		_clean_endline(next_lines->content);
		ft_memcpy(dm->tilemap->map[i],
			next_lines->content, ft_strlen(next_lines->content));
		next_lines = next_lines->next;
		i++;
	}
}

void	dm_load_tilemap_(t_datamodel *dm, t_list *next_lines)
{
	t_list	*lines_list;
	int		i;
	int		line_len;

	i = 0;
	while (next_lines && ((char *)next_lines->content)[0] == '\n')
		next_lines = next_lines->next;
	lines_list = next_lines;
	dm->tilemap = ut_scalloc(1, sizeof(t_tilemap));
	while (lines_list)
	{
		line_len = ft_strlen(lines_list->content);
		while (i < line_len)
		{
			if (!ft_strchr("NSWE10 \t\n", ((char *)lines_list->content)[i++]))
				ut_error_quit("Invalid map\n");
		}
		if (((char *)lines_list->content)[0] == '\0'
			|| !ft_strchr("NSWE10 \t\n", ((char *)lines_list->content)[0]))
			break ;
		lines_list = lines_list->next;
		++dm->tilemap->size.y;
		i = 0;
	}
	_load_map_data_(dm, next_lines);
}
