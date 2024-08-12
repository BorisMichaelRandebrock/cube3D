/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:28:29 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/12 16:51:34 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdio.h>

#define TEXTURE_COUNT	4
#define TEXTURE_SIZE	256
#define WALL_N			0
#define WALL_E			1
#define WALL_S			2
#define WALL_W			3

static	void	_load_texture_data(t_texture *tex)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	tex->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(uint32_t *));
	while (y < TEXTURE_SIZE)
	{
		tex->pixels[y] = ut_scalloc(TEXTURE_SIZE, sizeof(uint32_t));
		while (x < TEXTURE_SIZE)
		{
			tex->pixels[y][x] = px_decode_pixel(&tex->mlx_tex->pixels
				[i * tex->mlx_tex->bytes_per_pixel]);
			x++;
			i++;
		}
		x = 0;
		y++;
	}
}

void	wall_setup(t_datamodel *dm)
{
	int	i;

	dm->wall_tex = ut_scalloc(4, sizeof(t_texture *));
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		dm->wall_tex[i] = ut_scalloc(1, sizeof(t_texture));
		if (i == WALL_N)
			dm->wall_tex[i]->mlx_tex = mlx_load_png("res/north_texture.png");
		else if (i == WALL_E)
			dm->wall_tex[i]->mlx_tex = mlx_load_png("res/east_texture.png");
		else if (i == WALL_S)
			dm->wall_tex[i]->mlx_tex = mlx_load_png("res/south_texture.png");
		else if (i == WALL_W)
			dm->wall_tex[i]->mlx_tex = mlx_load_png("res/west_texture.png");
		_load_texture_data(dm->wall_tex[i++]);
	}
	i = 0;
	while (i < H_RES)
	{
		dm->columns[i] = mlx_new_image(dm->mlx, 1, V_RES);
		mlx_image_to_window(dm->mlx, dm->columns[i++], 0, 0);
	}
	mlx_loop_hook(dm->mlx, rc_cast_fan, dm);
	mlx_loop_hook(dm->mlx, wall_draw, dm);
}
