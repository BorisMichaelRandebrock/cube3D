/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:33:06 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/21 17:53:29 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_free_columns(t_datamodel *dm)
{
	int	i;

	i = 0;
	while (i < H_RES)
		mlx_delete_image(dm->mlx, dm->columns[i++]);
}

static void	_free_textures(t_datamodel *dm)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		mlx_delete_texture(dm->wall_tex[i]->mlx_tex);
		while (j < 256)
		{
			free(dm->wall_tex[i]->pixels[j++]);
		}
		j = 0;
		free(dm->wall_tex[i]->pixels);
		free(dm->wall_tex[i++]);
	}
	free(dm->wall_tex);
}

void	freexit(t_datamodel *dm)
{
	free(dm->no_tex_path);
	free(dm->so_tex_path);
	free(dm->we_tex_path);
	free(dm->ea_tex_path);
	free(dm->floor_raw);
	free(dm->ceiling_raw);
	dm_free_tilemap(dm->tilemap);
	free(dm->player);
	free(dm->fray);
	ft_lstclear(&dm->ray_list, free);
	_free_columns(dm);
	_free_textures(dm);
	mlx_delete_texture(dm->player_tex);
	mlx_delete_texture(dm->marker_tex);
	free(dm);
}

void	close_game(void *param)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	freexit(dm);
	mlx_terminate(param);
	exit(EXIT_SUCCESS);
}
