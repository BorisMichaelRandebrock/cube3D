/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:31:10 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bg_setup(t_datamodel *dm)
{
	mlx_image_t	*top;
	mlx_image_t	*bottom;
	int			y;
	int			x;

	top = mlx_new_image(dm->mlx, H_RES, V_RES / 2);
	bottom = mlx_new_image(dm->mlx, H_RES, V_RES / 2);
	x = 0;
	y = 0;
	while (y < V_RES / 2)
	{
		while (x < H_RES)
		{
			mlx_put_pixel(top, x, y, dm->ceiling_hex);
			mlx_put_pixel(bottom, x, y, dm->floor_hex);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(dm->mlx, top, 0, 0);
	mlx_image_to_window(dm->mlx, bottom, 0, V_RES / 2);
	mlx_set_instance_depth(&top->instances[0], 0);
	mlx_set_instance_depth(&bottom->instances[0], 0);
}
