#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "respath.h"
#include "cube3d.h"


#define CUB_FILE_ERROR -1
#define CUB_FILENAME 1
#define CUB_BUFFER 2048


void	close_game(void *param)
{
	mlx_terminate(param);
	exit(EXIT_SUCCESS);
}

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
		ut_error_quit("Cub file is empty.\n");
}

static void	_data_init(char *cub_filename)
{
	t_datamodel	*dm;
	t_list		*cub_lines;
	t_list		*next_lines;
	int			fd;

	dm = ut_scalloc(1, sizeof(t_datamodel));
	dm_get(dm);
	fd = open(cub_filename, O_RDONLY, 0777);
	if (fd == CUB_FILE_ERROR)
		ut_error_quit("Bad file argument.\n");
	cub_lines = NULL;
	_get_cub_lines(&cub_lines, fd);
	close(fd);
	next_lines = dm_load_tex_path(dm, cub_lines);
	next_lines = dm_load_colors(dm, next_lines);
	dm_load_tilemap_(dm, next_lines);
	ft_lstclear(&cub_lines, free);
	if (!dm_check_tex_files(dm))
		ut_error_quit("Wrong texture file.\n");
	if (!dm_check_colors(dm))
		ut_error_quit("Missing color values.\n");
	if (!dm_check_tilemap(dm))
		ut_error_quit("Invalid tilemap.\n");
	dm_load_player_data(dm);
}



/* static void	test(void *ship)
{
	t_datamodel *dm = get_dm(NULL);
	mlx_image_t *_ship = (mlx_image_t *)ship;

	_ship->instances[0].x = dm->player->pos.x;
	_ship->instances[0].y = dm->player->pos.y;
} */





int	main(int argc, char **argv)
{
	t_datamodel	*dm;
	mlx_texture_t	*icon;
	
	if (argc != 2)
		ut_error_quit("Wrong number of arguments.\n");
	_data_init(argv[CUB_FILENAME]);

	dm = dm_get(NULL);

	//BASIC WINDOW

	dm->mlx = mlx_init(H_RES, V_RES, "Cube3D", true);
	icon = mlx_load_png(ICON_TEX_PATH);
	mlx_set_icon(dm->mlx, icon);
	mlx_close_hook(dm->mlx, close_game, dm->mlx);
	mlx_key_hook(dm->mlx, pl_input, dm->mlx);
	bg_setup(dm);
	mm_setup(dm);

		//lanzar rayitos

	//mlx_texture_t	*wall = mlx_load_png("res/blank.png");
	//mlx_image_t		*wallimg = mlx_texture_to_image(dm->mlx, wall);
	
	//mlx_loop_hook(dm->mlx, wall_draw , wallimg);

		//test Dibujar navecita
	
/*	mlx_texture_t *shiptex = mlx_load_png("res/test_ship.png");
	mlx_image_t	*shipimg = mlx_texture_to_image(mlx, shiptex);
	mlx_image_to_window(mlx, shipimg, H_RES /2, V_RES /2);

	mlx_loop_hook(mlx, test , shipimg); */


	mlx_loop(dm->mlx);
	
//TODO gestionar image delete
/*	mlx_delete_image(mlx, top);
	mlx_delete_image(mlx, bottom); */
	
	close_game(dm->mlx);
	return (0);
}
