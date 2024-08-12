/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_tex_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:26 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/12 12:28:57 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "cube3d.h"

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
	*path = _trim_path(&line[PATH_OFFSET]);
	return (next_lines);
}

t_list	*dm_load_tex_path(t_datamodel *dm, t_list *next_lines)
{
	char	*line;
	t_list	*end_line;

	dm->no_tex_path = ft_strdup("");
	dm->so_tex_path = ft_strdup("");
	dm->we_tex_path = ft_strdup("");
	dm->ea_tex_path = ft_strdup("");
	while (next_lines)
	{
		line = next_lines->content;
		if (line[0] == 'N' && line[1] == 'O' && ut_sfree(dm->no_tex_path))
			end_line = _load_line(&dm->no_tex_path, next_lines);
		if (line[0] == 'S' && line[1] == 'O' && ut_sfree(dm->so_tex_path))
			end_line = _load_line(&dm->so_tex_path, next_lines);
		if (line[0] == 'W' && line[1] == 'E' && ut_sfree(dm->we_tex_path))
			end_line = _load_line(&dm->we_tex_path, next_lines);
		if (line[0] == 'E' && line[1] == 'A' && ut_sfree(dm->ea_tex_path))
			end_line = _load_line(&dm->ea_tex_path, next_lines);
		next_lines = next_lines->next;
	}
	if (!end_line)
		ut_error_quit("Wrong level file");
	return (end_line->next);
}
