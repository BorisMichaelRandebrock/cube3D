/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:29:41 by fmontser          #+#    #+#             */
/*   Updated: 2024/07/29 18:24:59 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "respath.h"
#include "cube3d.h"


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
		if (buffer[i] == '\n')
		{
			line = ft_strdup(buffer);
			ft_lstadd_back(cub_lines, ft_lstnew(line));
			i = 0;
			ft_memset(buffer, '\0', BUFSIZ);
			continue ;
		}
		i++;
	}
	line = ft_strdup(buffer);
	ft_lstadd_back(cub_lines, ft_lstnew(line));
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
	if (!dm_check_tex_files(dm))
		error_quit("Wrong texture file.\n");
	if (!dm_check_colors(dm))
		error_quit("Missing color values.\n");
	if (!dm_check_tilemap(dm))
		error_quit("Invalid tilemap.\n");
	dm_load_player_data(dm);
}


/* static void	test(void *param)
{
	(void)param;
	printf("x: %f y:%f\n", get_dm(NULL)->player->pos.x, get_dm(NULL)->player->pos.y);
	printf("rad: %f\n", get_dm(NULL)->player->orientation);
} */

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_datamodel	*dm;
	mlx_texture_t	*icon;
	
	if (argc != 2)
		error_quit("Wrong number of arguments.\n");
	_data_init(argv[CUB_FILENAME]);

	dm = get_dm(NULL);

	//BASIC WINDOW
	//mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(H_RES, V_RES, "Cube3D", true);
	icon = mlx_load_png(ICON_TEX_PATH);
	mlx_set_icon(mlx, icon);
	mlx_close_hook( mlx, close_game, mlx);
	mlx_key_hook(mlx, input_init, mlx);
	set_background(dm, mlx);



	
	//mlx_loop_hook(mlx, test , mlx);

	mlx_loop(mlx);
	
//TODO gestionar image delete	
/*	mlx_delete_image(mlx, top);
	mlx_delete_image(mlx, bottom); */
	
	close_game(mlx);
	return (0);
}
