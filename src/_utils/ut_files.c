/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:37 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 16:01:24 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*ut_sload_texture(char *filepath)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(filepath);
	if (!texture)
		ut_error_quit("Texture file error\n");
	return(texture);
}

