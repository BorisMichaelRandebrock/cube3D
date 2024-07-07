/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fran <fran@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:51:44 by fran              #+#    #+#             */
/*   Updated: 2024/07/07 22:52:19 by fran             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* allowed funcs

	open, close, read, write,
	printf, malloc, free,
	perror,strerror,
	exit

	math library, minilibx library

 */
#include <unistd.h>
#include <fcntl.h>

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

static void	get_tilemap_size()
{
	
}
static t_tilemap	load_tilemap(int fd)
{
	t_tilemap *tilemap;

	tilemap = ft_calloc(1, sizeof(t_tilemap));
	//TODO copiar mapa a la ram

}

int	main(int argc, char **argv)
{
	t_tilemap *tilemap;
	int	level_fd;

	if (argc != 2)
		return (1);

	level_fd = open(argv[1], O_RDONLY, 0777);
	tilemap = load_tilemap(level_fd);
	close(level_fd);
	return (0);
}

