/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_check_tex_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:33:55 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 17:33:55 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "cube3d.h"

#define NUM_TEXTURES 4
#define STD_FDS	2 

bool	dm_check_tex_files(t_datamodel *dm)
{
	short	flag;
	int		fd;
	void	*paths[NUM_TEXTURES];
	int		i;

	i = 0;
	paths[0] = dm->no_tex_path;
	paths[1] = dm->so_tex_path;
	paths[2] = dm->we_tex_path;
	paths[3] = dm->ea_tex_path;
	while (i < NUM_TEXTURES)
	{
		fd = open(paths[i++], O_RDONLY, 0777);
		if (fd > STD_FDS)
			flag++;
		close(fd);
	}
	if (flag < NUM_TEXTURES)
		return (false);
	return (true);
}
