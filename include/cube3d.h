#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include "libft.h"
# include "MLX42.h"

# define H_RES 1336
# define V_RES 768
# define MM_RES 16


typedef struct t_timon
{
	mlx_image_t	*img[H_RES];
}	t_timon;

typedef struct s_point
{
	double		x;
	double		y;
}	t_point;

typedef struct s_ray
{
	double		length;
	t_point		endpoint;
	uint32_t	h_pos;
}	t_ray;

typedef struct s_rect
{
	int			x;
	int			y;
}	t_rect;

typedef struct s_coldet_rect
{
	t_point	top_left;
	t_point	bottom_right;
}	t_coldet_rect;

typedef struct s_tilemap
{
	t_rect		size;
	char		**map;
	t_point		spawn_point;
	char		spawn_char;
}	t_tilemap;

typedef struct s_player
{
	int			mm_size;
	t_point		pos;
	double		rad;
	t_ray		*coldet_ray;
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
	t_ray		*front_ray;
	t_list		*ray_list;
}	t_datamodel;


void			close_game(void* param);
double			ut_deg_to_rad(double degrees);
double			ut_rad_to_deg(double radians);
double			ut_rad_mirror(double radians);
void			*ut_scalloc(size_t nmemb, size_t size);
bool			ut_sfree(void *ptr);
void			ut_error_quit(char *str);
void			ut_print_colors(const char *str, const char *color);
double			ut_clamp(double min, double max, double num);
t_point			ut_get_direction(double radians);
t_list			*ut_sort_rays(t_list *lst);
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
void    		dm_populate_columns(t_datamodel *dm);
void			pl_input(mlx_key_data_t keydata, void *param);
void			pl_walk(int vect, double rad_mod);
void			pl_rotate(int mag);
void			bg_setup(t_datamodel *dm);
void			mm_setup(t_datamodel *dm);
void			mm_draw_destination(void *marker);
void			mm_draw_heading(void *marker);
void			mm_draw_ray(void *minimap);
void			mm_draw_player(void *param);
void			rc_dda(void *ray);
void			rc_cast(void *ray);
void			rc_cast_offset(void *ray, double rad_offset);
void			rc_cast_fan(void *param);
void			wall_setup(t_datamodel *dm);
void			wall_draw(void *dm);

#endif
