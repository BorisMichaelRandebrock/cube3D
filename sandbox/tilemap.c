/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:51:44 by fran              #+#    #+#             */
/*   Updated: 2024/07/09 21:58:39 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* allowed funcs

	open, close, read, write,
	printf, malloc, free,
	perror,strerror,
	exit

	math library, minilibx library

 */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_rect
{
	int	x;
	int	y;
}	t_rect;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_tilemap
{
	t_rect	size;
	char	**map;
}	t_tilemap;


void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}


static bool	is_valid_map_character(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\n'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}


static void	get_tilemap_size(int tilemap_fd, t_tilemap *tilemap)
{
	char	read_buff;
	int		x_size;

	x_size = 0;
	while (read(tilemap_fd, &read_buff, sizeof(char)) == 1 && is_valid_map_character(read_buff))
	{
		if (tilemap->size.y == 0)
			tilemap->size.y++;
		if (read_buff != '\n')
			x_size++;
		else
		{
			tilemap->size.y++;
			if (tilemap->size.x < x_size)
				tilemap->size.x = x_size;
			x_size = 0;
		}
	}
}

static t_tilemap	*load_tilemap(int tilemap_fd)
{
	t_tilemap	*tilemap;
	int			i;

	tilemap = ft_calloc(1, sizeof(t_tilemap));
	get_tilemap_size(tilemap_fd, tilemap);

	//TODO debug borrar
	printf("map size is {%d,%d}\n", tilemap->size.x, tilemap->size.y);

	i = 0;
	tilemap->map = ft_calloc(tilemap->size.y, sizeof(char *));
	while (i < tilemap->size.y)
		tilemap->map[i++] = ft_calloc(tilemap->size.x, sizeof(char));

	
	//TODO copiar mapa a la ram (refactor, abrir el archivo y cerrarlo aqui...)
	return (tilemap);
}

int	main(int argc, char **argv)
{
	t_tilemap *tilemap;
	int	level_fd;

	if (argc != 2)
		return (1);

	level_fd = open(argv[1], O_RDONLY, 0777);

	//TODO Lectura de datos adicionales...
	
	tilemap = load_tilemap(level_fd);
	close(level_fd);
	return (0);
}

