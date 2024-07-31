#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include "libft.h"
# include "MLX42.h"

# define H_RES 1024
# define V_RES 786
# define MM_RES 16

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_rect
{
	int			x;
	int			y;
}	t_rect;

typedef struct s_tilemap
{
	t_rect		size;
	char		**map;
	t_point		spawn_point;
	char		spawn_char;
}	t_tilemap;

typedef struct s_player
{
	t_point		pos;
	float		orientation;	
}	t_player;

typedef struct s_datamodel
{
	char		*no_tex_path;
	char		*so_tex_path;
	char		*we_tex_path;
	char		*ea_tex_path;
	char		*ceiling_raw;
	uint32_t	ceiling_hex;
	char		*floor_raw;
	uint32_t	floor_hex;
	t_tilemap	*tilemap;
	t_player	*player;
	mlx_t		*mlx;
}	t_datamodel;


void			close_game(void* param);
double			ut_deg_to_rad(double degrees);
double			ut_rad_to_deg(double radians);
void			*ut_scalloc(size_t nmemb, size_t size);
bool			ut_sfree(void *ptr);
void			ut_error_quit(char *str);
void			ut_print_colors(const char *str, const char *color);
float			ut_clamp(float min, float max, float num);
t_datamodel		*dm_get(t_datamodel *dm);
t_list			*dm_load_tex_path(t_datamodel *dm, t_list *cub_lines);
t_list			*dm_load_colors(t_datamodel *dm, t_list *cub_lines);
void			dm_load_player_data(t_datamodel *dm);
void			dm_load_tilemap_(t_datamodel *dm, t_list *cub_lines);
bool			dm_check_tex_files(t_datamodel *dm);
bool			dm_check_colors(t_datamodel *dm);
bool			dm_check_tilemap(t_datamodel *dm);
void			dm_free_tilemap(t_tilemap *tilemap);
t_tilemap		*dm_copy_tilemap_(t_tilemap *tilemap);
void			pl_input(mlx_key_data_t keydata, void *param);
void			pl_walk(int vect, float rad_mod);
void			pl_rotate(float rotation);
void			bg_setup(t_datamodel *dm);
void			mm_setup(t_datamodel *dm);
void			mm_draw_minimap(void *minimap);
void			mm_draw_player(void *param);
float			rc_cast(void);
void			wall_draw(void *mlx);
#endif
