#include "cube3d.h"
#include <stdio.h>



//TODO quitar TEX RESOLUTION hardcoded 256
#define TEXTURE_SIZE 256

void	wall_setup(t_datamodel *dm)
{
	mlx_texture_t	*texture;
	t_texture		*walltex;
	int	x;
	int	y;
	int	i;

	texture = mlx_load_png("res/wall.png");
	walltex = ut_scalloc(1, sizeof(t_texture));
	walltex->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(int32_t *));

	x = 0;
	y = 0;
	i = 0;
	while (y < TEXTURE_SIZE)
	{
		walltex->pixels[y] = ut_scalloc(TEXTURE_SIZE, sizeof(uint32_t));
		while (x < TEXTURE_SIZE)
		{
			walltex->pixels[y][x] = decode_pixel(&texture->pixels[i * texture->bytes_per_pixel]);
			x++;
			i++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(texture);

	x = 0;
	while (x < H_RES)
	{
		dm->columns[x] = mlx_new_image(dm->mlx, 1, V_RES);
		mlx_image_to_window(dm->mlx, dm->columns[x], 0,0);
		x++;
	}
	mlx_loop_hook(dm->mlx, rc_cast_fan, dm);
	mlx_loop_hook(dm->mlx, wall_draw, walltex);
}
