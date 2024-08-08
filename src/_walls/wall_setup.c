#include "cube3d.h"
#include <stdio.h>

#define TEXTURE_COUNT	4
#define TEXTURE_SIZE	256
#define WALL_N			0
#define WALL_E			1
#define WALL_S			2
#define WALL_W			3


static	void _load_texture_data(t_texture *texture)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (y < TEXTURE_SIZE)
	{
		texture->pixels[y] = ut_scalloc(TEXTURE_SIZE, sizeof(uint32_t));
		while (x < TEXTURE_SIZE)
		{
			uint8_t test = texture->mlx_texture->pixels[i * texture->mlx_texture->bytes_per_pixel];
			texture->pixels[y][x] = px_decode_pixel(&test);
			x++;
			i++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(texture->mlx_texture);
}

void	wall_setup(t_datamodel *dm)
{
	int	i;

	//TODO arreglar segfault!! @@@@@@@@@
	dm->wall_tex = ut_scalloc(4, sizeof(t_texture *));

	dm->wall_tex[WALL_S]->mlx_texture = mlx_load_png("res/south_texture.png");
	dm->wall_tex[WALL_N]->mlx_texture = mlx_load_png("res/north_texture.png");
	dm->wall_tex[WALL_E]->mlx_texture = mlx_load_png("res/east_texture.png");
	dm->wall_tex[WALL_W]->mlx_texture = mlx_load_png("res/west_texture.png");
	dm->wall_tex[WALL_S]->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(int32_t *));
	dm->wall_tex[WALL_N]->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(int32_t *));
	dm->wall_tex[WALL_E]->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(int32_t *));
	dm->wall_tex[WALL_W]->pixels = ut_scalloc(TEXTURE_SIZE, sizeof(int32_t *));
	i = 0;
	while (i < TEXTURE_COUNT)
		_load_texture_data(dm->wall_tex[i++]);
	i = 0;
	while (i < H_RES)
	{
		dm->columns[i] = mlx_new_image(dm->mlx, 1, V_RES);
		mlx_image_to_window(dm->mlx, dm->columns[i], 0,0);
		i++;
	}
	mlx_loop_hook(dm->mlx, rc_cast_fan, dm);
	mlx_loop_hook(dm->mlx, wall_draw, NULL);
}
