/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:11:02 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 18:11:15 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"
#include "rad.h"

void	pl_input(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_game(param);
	else if (keydata.key == MLX_KEY_A && keydata.action >= MLX_PRESS)
		pl_walk(-1, RAD_90);
	else if (keydata.key == MLX_KEY_D && keydata.action >= MLX_PRESS)
		pl_walk(1, RAD_90);
	else if (keydata.key == MLX_KEY_W && keydata.action >= MLX_PRESS)
		pl_walk(1, RAD_0);
	else if (keydata.key == MLX_KEY_S && keydata.action >= MLX_PRESS)
		pl_walk(-1, RAD_0);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_Q)
		&& keydata.action >= MLX_PRESS)
		pl_rotate(-1);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_E)
		&& keydata.action >= MLX_PRESS)
		pl_rotate(1);
}
