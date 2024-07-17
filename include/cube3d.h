#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_rect
{
	int	x;
	int	y;
}	t_rect;

typedef struct s_tilemap
{
	t_rect	size;
	char	**map;
}	t_tilemap;


typedef struct s_datamodel
{
	char		*no_tex_path;
	char		*so_tex_path;
	char		*we_tex_path;
	char		*ea_tex_path;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	t_tilemap	*tilemap;
}	t_datamodel;

t_datamodel	*get_dm(t_datamodel *dm);
void		free_dm(t_datamodel *dm);
void	*	scalloc(size_t nmemb, size_t size);
void		error_quit(char *str);
void		print_colors(const char *str, const char *color);
void		dm_load_tex_path(t_datamodel *dm, int fd);
void		dm_load_colors(t_datamodel *dm, int fd);
void		dm_load_tilemap_(t_datamodel *dm, int fd);
bool		dm_check_tex_files(t_datamodel *dm);

#endif
