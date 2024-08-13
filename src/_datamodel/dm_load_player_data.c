/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_load_player_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:35:28 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "rad.h"

#define MM_SIZE	16

void	dm_load_player_data(t_datamodel *dm)
{
	char	c;

	dm->player = ut_scalloc(1, sizeof(t_player));
	dm->player->pos = dm->tilemap->spawn_point;
	dm->player->pos.x += 0.5;
	dm->player->pos.y += 0.5;
	c = dm->tilemap->spawn_char;
	if (c == 'N')
		dm->player->yaw = RAD_270;
	else if (c == 'S')
		dm->player->yaw = RAD_90;
	else if (c == 'W')
		dm->player->yaw = RAD_180;
	else if (c == 'E')
		dm->player->yaw = RAD_0;
	dm->player->yaw = ut_norm_angle(dm->player->yaw);
	dm->player->mm_size = MM_SIZE;
}
