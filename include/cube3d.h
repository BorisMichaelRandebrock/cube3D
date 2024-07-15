#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <inttypes.h>

# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define DARK_RED "\033[0;31m"
# define ROSA "\033[38;2;255;102;204m"
# define RES "\033[0m"


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

t_datamodel	*load_cub(char *filename);
void	*__calloc(size_t nmemb, size_t size);

#endif
