/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:36:11 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	mm_draw_player(void *player)
{
	t_datamodel		*dm;
	mlx_instance_t	*_player;

	dm = dm_get(NULL);
	_player = (mlx_instance_t *)player;
	_player->x = dm->player->pos.x * MM_RES - (dm->player->mm_size / 2);
	_player->y = dm->player->pos.y * MM_RES - (dm->player->mm_size / 2);
	mlx_set_instance_depth(_player, 11);
}

void	mm_draw_destination(void *marker)
{
	t_datamodel		*dm;
	mlx_instance_t	*_marker;

	dm = dm_get(NULL);
	_marker = (mlx_instance_t *)marker;
	_marker->x = (dm->fray->endpoint.x * MM_RES) - (dm->player->mm_size / 4);
	_marker->y = (dm->fray->endpoint.y * MM_RES) - (dm->player->mm_size / 4);
	mlx_set_instance_depth(_marker, 11);
}

void	mm_draw_heading(void *heading)
{
	t_datamodel		*dm;
	mlx_instance_t	*_heading;

	dm = dm_get(NULL);
	_heading = (mlx_instance_t *)heading;
	_heading->x = (dm->player->pos.x * MM_RES) - (dm->player->mm_size / 4);
	_heading->y = (dm->player->pos.y * MM_RES) - (dm->player->mm_size / 4);
	_heading->x += ut_cos(dm->player->yaw) * MM_RES;
	_heading->y += ut_sin(dm->player->yaw) * MM_RES;
	mlx_set_instance_depth(_heading, 12);
}
