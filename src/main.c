/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:29:41 by fmontser          #+#    #+#             */
/*   Updated: 2024/07/16 19:44:50 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "cube3d.h"
#include "libft.h"
#include "MLX42.h"

#define CUB_FILENAME 1

static void	_data_init(char *cub_filename)
{
	t_datamodel	*dm;
	int			fd;

	dm = scalloc(1, sizeof(t_datamodel));
	get_dm(dm);
	fd = open(cub_filename, O_RDONLY, 0777);
	//TODO excepcion cub file not found!
	dm_load_tex_path(dm, fd);
	dm_load_colors(dm, fd);
	dm_load_tilemap_(dm, fd);
	close(fd);
	dm_check_tex_files(dm);
}

static void	_termination(void)
{
	free_dm(NULL);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	
	// Comprobar que se ha pasado 1 argumento
	if (argc != 2)
		return (1);
	_data_init(argv[CUB_FILENAME]);



	//BASIC WINDOW
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(1920, 1080, "Cube3D", true);
	mlx_new_image(mlx, 256, 256);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	//TODO mover mlx a termination...

	// FREE...
	_termination();

	return (0);
}
