/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:36:43 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/12 18:20:28 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

static void	_scale(t_datamodel *dm, t_ray *ray, mlx_image_t *img, double height)
{
	uint32_t	sy;
	uint32_t	dy;
	uint32_t	pixel;
	double		ratio;

	sy = 0;
	dy = 0;
	while (dy < height - 1)
	{
		if (sy > 255)
			break ;
		ratio = height / 256;
		sy = dy / ratio;
		pixel = dm->wall_tex[ray->wall_side]->pixels[sy][ray->h_tex_pos];
		pixel = px_pixel_shader(pixel, ray->length);
		mlx_put_pixel(img, 0, dy, pixel);
		dy++;
	}
}

void	wall_draw(void *dm)
{
	mlx_image_t	*img;
	t_ray		*ray;
	t_list		*_ray_list;
	double		new_height;
	int			i;

	_ray_list = ((t_datamodel *)dm)->ray_list;
	i = 0;
	while (_ray_list)
	{
		ray = ((t_ray *)_ray_list->content);
		img = ((t_datamodel *)dm)->columns[i++];
		new_height = ut_clamp(1, V_RES, V_RES / ray->length);
		mlx_resize_image(img, 1, new_height);
		_scale(dm, ray, img, new_height);
		img->instances[0].x = ray->h_pos;
		img->instances[0].y = (V_RES / 2) - (new_height / 2);
		_ray_list = _ray_list->next;
		mlx_set_instance_depth(&img->instances[0], 1);
	}
}
