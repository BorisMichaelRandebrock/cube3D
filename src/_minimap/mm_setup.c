/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:38:15 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/12 18:31:20 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	_paint_map(mlx_image_t *minimap, t_rect *grid, t_rect *px_grid)
{
	t_datamodel	*dm;
	t_rect		_grid;
	t_rect		_px_grid;

	dm = dm_get(NULL);
	_grid = *grid;
	_px_grid = *px_grid;
	if (dm->tilemap->map[_grid.y][_grid.x] == '1')
	{
		mlx_put_pixel(minimap, _px_grid.x + (_grid.x * MM_RES),
			_px_grid.y + (_grid.y * MM_RES), 0xFFFFFFFF);
	}
	else
	{
		mlx_put_pixel(minimap, _px_grid.x + (_grid.x * MM_RES),
			_px_grid.y + (_grid.y * MM_RES), 0x000000FF);
	}
	px_grid->x++;
}

static void	_mm_build_minimap(t_datamodel *dm, mlx_image_t *minimap)
{
	t_rect		grid;
	t_rect		px_grid;

	grid.y = 0;
	grid.x = 0;
	px_grid.x = 0;
	px_grid.y = 0;
	while (grid.y < dm->tilemap->size.y)
	{
		while (grid.x < dm->tilemap->size.x)
		{
			while (px_grid.y < MM_RES)
			{
				while (px_grid.x < MM_RES)
					_paint_map(minimap, &grid, &px_grid);
				px_grid.x = 0;
				px_grid.y++;
			}
			px_grid.y = 0;
			grid.x ++;
		}
		grid.x = 0;
		grid.y++;
	}
}

void	mm_setup(t_datamodel *dm)
{
	mlx_image_t	*minimap;
	mlx_image_t	*player;
	mlx_image_t	*marker;

	minimap = mlx_new_image(dm->mlx, dm->tilemap->size.x * MM_RES,
			dm->tilemap->size.y * MM_RES);
	_mm_build_minimap(dm, minimap);
	mlx_image_to_window(dm->mlx, minimap, 0, 0);
	mlx_set_instance_depth(&((mlx_instance_t *)minimap->instances)[0], 10);
	mlx_loop_hook(dm->mlx, rc_cast, dm->fray);
	dm->player_tex = mlx_load_png("res/mm_player.png");
	player = mlx_texture_to_image(dm->mlx, dm->player_tex);
	mlx_resize_image(player, dm->player->mm_size, dm->player->mm_size);
	mlx_image_to_window(dm->mlx, player, 0, 0);
	mlx_loop_hook(dm->mlx, mm_draw_player, &player->instances[0]);
	dm->marker_tex = mlx_load_png("res/mm_player.png");
	marker = mlx_texture_to_image(dm->mlx, dm->marker_tex);
	mlx_resize_image(marker, dm->player->mm_size / 2, dm->player->mm_size / 2);
	mlx_image_to_window(dm->mlx, marker, 0, 0);
	mlx_image_to_window(dm->mlx, marker, 0, 0);
	mlx_loop_hook(dm->mlx, mm_draw_destination, &marker->instances[0]);
	mlx_loop_hook(dm->mlx, mm_draw_heading, &marker->instances[1]);
}
