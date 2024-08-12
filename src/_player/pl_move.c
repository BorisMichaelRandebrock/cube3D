/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:11:28 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/12 16:47:42 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube3d.h"
#include "rad.h"
#include <stdio.h>

#define MOVE_SPEED 0.2
#define ROT_SPEED 0.05
#define MOUSE_SENSITIVITY 0.04
#define COLDET_SCALE 0.3

static bool	pl_sat_coldet(t_datamodel *dm, t_point delta)
{
	t_coldet_rect	rect;

	rect.top_l.x = delta.x - (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.top_l.y = delta.y - (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.bottom_r.x = delta.x + (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	rect.bottom_r.y = delta.y + (dm->player->mm_size / MM_RES) * COLDET_SCALE;
	if (dm->tilemap->map[(int)rect.top_l.y][(int)rect.top_l.x] == '1'
		|| dm->tilemap->map[(int)rect.bottom_r.y][(int)rect.top_l.x] == '1'
		|| dm->tilemap->map[(int)rect.bottom_r.y][(int)rect.bottom_r.x] == '1'
		|| dm->tilemap->map[(int)rect.top_l.y][(int)rect.bottom_r.x] == '1')
		return (true);
	return (false);
}

//TODO factor in delta time
void	pl_walk(int mag, double radians)
{
	t_datamodel	*dm;
	t_point		delta;

	dm = dm_get(NULL);
	delta = dm->player->pos;
	delta.x += mag * MOVE_SPEED * ut_cos(dm->player->yaw + radians);
	delta.y += mag * MOVE_SPEED * ut_sin(dm->player->yaw + radians);
	if (pl_sat_coldet(dm, delta))
		return ;
	dm->player->pos = delta;
}

void	pl_rotate(int mag)
{
	t_datamodel	*dm;

	dm = dm_get(NULL);
	dm->player->yaw += (mag * ROT_SPEED);
	dm->player->yaw = ut_norm_angle(dm->player->yaw);
}

void	pl_mouse_rotate(double x, double y, void *param)
{
	static double	last = 0;
	double			delta;
	t_datamodel		*dm;

	(void)param;
	(void)y;
	delta = fabs(last - x);
	dm = dm_get(NULL);
	if (x < last)
		dm->player->yaw
			+= ut_norm_angle(delta * MOUSE_SENSITIVITY * dm->mlx->delta_time);
	else if (x > last)
		dm->player->yaw
			-= ut_norm_angle(delta * MOUSE_SENSITIVITY * dm->mlx->delta_time);
	last = x;
}
