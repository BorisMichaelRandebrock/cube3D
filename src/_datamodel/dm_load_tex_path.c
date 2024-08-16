/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_tex_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:26 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 17:14:13 by fmontser         ###   ########.fr       */
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

static t_list	*_load_line(char **path, t_list *next_lines)
{
	char	*line;

	line = next_lines->content;
	if (line[PATH_OFFSET - 1] != ' ')
		ut_error_quit("Missing texture path\n");
	line = _trim_path(&line[PATH_OFFSET]);
	if (*path[0] != '\0')
		ut_error_quit("Texture already assigned\n");
	ut_sfree(*path);
	*path = ft_strdup(line);
	free(line); //TODO if not: 90 bytes lost - 7 errors causado por la minilibx en strncmp
	return (next_lines);
}

t_list	*dm_load_tex_path(t_datamodel *dm, t_list *next_lines)
{
	char	*line;
	t_list	*end_line;

	while (next_lines)
	{
		line = next_lines->content;
		if (line[0] == 'N' && line[1] == 'O')
			end_line = _load_line(&dm->no_tex_path, next_lines);
		if (line[0] == 'S' && line[1] == 'O')
			end_line = _load_line(&dm->so_tex_path, next_lines);
		if (line[0] == 'W' && line[1] == 'E')
			end_line = _load_line(&dm->we_tex_path, next_lines);
		if (line[0] == 'E' && line[1] == 'A')
			end_line = _load_line(&dm->ea_tex_path, next_lines);
		next_lines = next_lines->next;
	}
	if (!end_line)
		ut_error_quit("Wrong level file");
	return (end_line->next);
}
