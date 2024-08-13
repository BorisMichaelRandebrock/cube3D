/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:10 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 17:47:43 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"

static	void _check_dupe(char *raw_color)
{
	if(raw_color[0] != '\0')
		ut_error_quit("Color entry duplicated\n");
}

t_list	*dm_load_colors(t_datamodel *dm, t_list *next_lines)
{
	char	*line;
	t_list	*end_line;

	dm->floor_hex = -1;
	dm->ceiling_hex = -1;
	while (next_lines)
	{
		line = next_lines->content;
		if (line[0] == 'F')
		{
			_check_dupe(dm->floor_raw);
			free(dm->floor_raw);
			dm->floor_raw = ft_strdup(line);
			end_line = next_lines;
		}
		else if (line[0] == 'C')
		{
			_check_dupe(dm->ceiling_raw);
			free(dm->ceiling_raw);
			dm->ceiling_raw = ft_strdup(line);
			end_line = next_lines;
		}
		next_lines = next_lines->next;
	}
	return (end_line->next);
}
