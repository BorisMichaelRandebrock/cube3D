/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:29:41 by fmontser          #+#    #+#             */
/*   Updated: 2024/07/15 12:36:43 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube3d.h"
#include "libft.h"
#include "MLX42.h"

#define CUB_FILENAME 1

int	main(int argc, char **argv)
{
	t_datamodel *datamodel;
	
	// Comprobar que se ha pasado 1 argumento
	if (argc != 2)
		return (1);

	datamodel = load_cub(argv[CUB_FILENAME]);
	(void)datamodel;


	//return (0);


	mlx_t* mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(1920, 1080, "Cube3D", true);
	mlx_new_image(mlx, 256, 256);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	//TODO free datamodel
	return (0);
}
