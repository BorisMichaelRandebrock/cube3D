#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include "libft.h"
# include "MLX42.h"

# define H_RES 640
# define V_RES 480
# define MM_RES 8

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

t_datamodel		*get_dm(t_datamodel *dm);
float			clamp(float min, float max, float num);
void			*scalloc(size_t nmemb, size_t size);
bool			sfree(void *ptr);
void			error_quit(char *str);
void			print_colors(const char *str, const char *color);
t_list			*dm_load_tex_path(t_datamodel *dm, t_list *cub_lines);
t_list			*dm_load_colors(t_datamodel *dm, t_list *cub_lines);
void			dm_load_player_data(t_datamodel *dm);
void			dm_load_tilemap_(t_datamodel *dm, t_list *cub_lines);
bool			dm_check_tex_files(t_datamodel *dm);
bool			dm_check_colors(t_datamodel *dm);
bool			dm_check_tilemap(t_datamodel *dm);
void			dm_free_tilemap(t_tilemap *tilemap);
t_tilemap		*dm_copy_tilemap_(t_tilemap *tilemap);
double			deg_to_rad(double degrees);
double			rad_to_deg(double radians);
void			input_init(mlx_key_data_t keydata, void *param);
void			close_game(void* param);
void			move_player_walk(int vect, float rad_mod);
void			rotate_player(float rotation);
void			set_background(t_datamodel *dm, mlx_t *mlx);
void			draw_wall(void *mlx);
void			mm_build_minimap(mlx_image_t *minimap);
void			mm_draw_minimap(void *minimap);
float			cast_ray(void);
#endif
