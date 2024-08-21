/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_tex_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:26 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/21 17:54:26 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "cub3d.h"

#define PATH_OFFSET 3

static char	*_trim_path(char *buffer)
{
	char	*path;

	path = ft_strdup(buffer);
	*(ft_strchr(path, '\n')) = '\0';
	return (path);
}

static int	_get_offset(int path_offset, char *line)
{
	int	i;
	int	line_len;

	i = path_offset;
	line_len = ft_strlen(line);
	while (i < line_len)
	{
		if (line[i] == ' ')
			path_offset++;
		i++;
	}
	return (path_offset);
}

static t_list	*_load_line(char **path, t_list *next_lines)
{
	char	*line;
	int		path_offset;

	line = next_lines->content;
	path_offset = _get_offset(PATH_OFFSET, line);
	if (line[path_offset - 1] != ' ')
		ut_error_quit("Missing texture path\n");
	line = _trim_path(&line[path_offset]);
	if (*path[0] != '\0')
		ut_error_quit("Texture already assigned\n");
	ut_sfree(*path);
	*path = ft_strdup(line);
	free(line);
	return (next_lines);
}

t_list	*dm_load_tex_path(t_datamodel *dm, t_list *next_lines)
{
	char	*line;

	line = next_lines->content;
	if (line[0] == 'N' && line[1] == 'O')
		_load_line(&dm->no_tex_path, next_lines);
	if (line[0] == 'S' && line[1] == 'O')
		_load_line(&dm->so_tex_path, next_lines);
	if (line[0] == 'W' && line[1] == 'E')
		_load_line(&dm->we_tex_path, next_lines);
	if (line[0] == 'E' && line[1] == 'A')
		_load_line(&dm->ea_tex_path, next_lines);
	if (!next_lines->next)
		ut_error_quit("Wrong level file");
	return (next_lines->next);
}
