/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:29:41 by fmontser          #+#    #+#             */
/*   Updated: 2024/07/18 13:53:12 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "cube3d.h"
#include "MLX42.h"

#define CUB_FILE_ERROR -1
#define CUB_FILENAME 1
#define CUB_BUFFER 2048

static void _get_cub_lines(t_list **cub_lines, int fd)
{
	int		i;
	char	buffer[BUFSIZ];
	char	*line;

	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
			continue ;
		if (buffer[i] == '\n')
		{
			line = ft_strdup(buffer);
			ft_lstadd_back(cub_lines, ft_lstnew(line));
			i = 0;
			continue ;
		}
		i++;
	}
	if (cub_lines == NULL)
		error_quit("Cub file is empty.\n");
}

static void	_data_init(char *cub_filename)
{
	t_datamodel	*dm;
	t_list		*cub_lines;
	t_list		*next_lines;
	int			fd;

	dm = scalloc(1, sizeof(t_datamodel));
	get_dm(dm);
	fd = open(cub_filename, O_RDONLY, 0777);
	if (fd == CUB_FILE_ERROR)
		error_quit("Bad file argument.\n");
	cub_lines = NULL;
	_get_cub_lines(&cub_lines, fd);
	close(fd);
	next_lines = dm_load_tex_path(dm, cub_lines);
	next_lines = dm_load_colors(dm, next_lines);
	dm_load_tilemap_(dm, next_lines);
	ft_lstclear(&cub_lines, free);

	/* 
	if (!dm_check_tex_files(dm))
		error_quit("Wrong texture file.\n");
	if (!dm_check_colors(dm))
		error_quit("Missing color values.\n"); */
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	
	if (argc != 2)
		error_quit("Wrong number of arguments.\n");
	_data_init(argv[CUB_FILENAME]);



	//BASIC WINDOW
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(1920, 1080, "Cube3D", true);
	mlx_new_image(mlx, 256, 256);
	mlx_loop(mlx);

	
	mlx_terminate(mlx);
	exit(EXIT_SUCCESS);

	return (0);
}
