
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

/* static bool	is_valid_map_character(char c)
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
static t_tilemap	*load_tilemap(char *filename)
{
	int			level_fd;
	t_tilemap	*tilemap; 
	int			i;

	level_fd = open(filename, O_RDONLY, 0777);
	tilemap = ft_calloc(1, sizeof(t_tilemap));
	get_tilemap_size(level_fd, tilemap);
	close(level_fd);
	//TODO debug borrar
	printf("map size is {%d,%d}\n", tilemap->size.x, tilemap->size.y);

	i = 0;
	tilemap->map = ft_calloc(tilemap->size.y, sizeof(char *));
	while (i < tilemap->size.y)
		tilemap->map[i++] = ft_calloc(tilemap->size.x, sizeof(char));
	
	level_fd = open(filename, O_RDONLY, 0777);
	//TODO copiar mapa a la ram (refactor, abrir el archivo y cerrarlo aqui...)
	close(level_fd);

	return (tilemap);
} */
#define ELEMENT_PATH 3

t_datamodel	*load_cub(char *filename)
{
	int		fd;
	int		i;
	char	buffer[BUFSIZ];
	t_datamodel *datamodel;

	datamodel = ft_calloc(1, sizeof(t_datamodel));
	ft_memset(buffer, '\0', BUFSIZ);

	//LOAD ELEMENT PATHS
	fd = open(filename, O_RDONLY, 0777);

	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
		{
			ft_memset(buffer, '\0', BUFSIZ);
			break;
		}
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'N' && buffer[1] == 'O')
			{
				datamodel->no_tex_path = ft_strdup(&buffer[ELEMENT_PATH]);
				*(ft_strchr(datamodel->no_tex_path, '\n')) = '\0';
			}
			if (buffer[0] == 'S' && buffer[1] == 'O')
			{
				datamodel->so_tex_path = ft_strdup(&buffer[ELEMENT_PATH]);
				*(ft_strchr(datamodel->so_tex_path, '\n')) = '\0';
			}
			if (buffer[0] == 'W' && buffer[1] == 'E')
			{
				datamodel->we_tex_path = ft_strdup(&buffer[ELEMENT_PATH]);
				*(ft_strchr(datamodel->we_tex_path, '\n')) = '\0';
			}
			if (buffer[0] == 'E' && buffer[1] == 'A')
			{
				datamodel->ea_tex_path = ft_strdup(&buffer[ELEMENT_PATH]);
				*(ft_strchr(datamodel->ea_tex_path, '\n')) = '\0';
			}
			

			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			continue ;
		}
		i++;
	}

	//LOAD AND CONVERT RGBA TO HEX
	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
		{
			ft_memset(buffer, '\0', BUFSIZ);
			break;
		}
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'F' || buffer[0] == 'C')
			{
				int	color;

				char *rgb = ft_strdup(&buffer[2]);
				char **split_values = ft_split(rgb, ',');
				color = 0;
				int	temp = ft_atoi(split_values[0]);
				temp <<= 24;
				color |= temp;
				temp = ft_atoi(split_values[1]);
				temp <<= 16;
				color |= temp;
				temp = ft_atoi(split_values[2]);
				temp <<= 8;
				color |= temp;
				free(rgb);
				free(split_values);
				if (buffer[0] == 'F')
					datamodel->floor_color = color;
				else if (buffer[0] == 'C')
					datamodel->ceiling_color = color;
			}
			ft_memset(buffer, '\0', BUFSIZ);
			i = 0;
			continue ;
		}
		i++;
	}

	//LOAD MAP
	char	*row;
	t_list	*head;
	t_list	*row_list;

	datamodel->tilemap = ft_calloc(1, sizeof(t_tilemap));

	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
		{
			row = ft_strdup(buffer);
			row[ft_strlen(row) - 1] = '\0'; 
			ft_lstadd_back(&row_list, ft_lstnew(row));
			ft_memset(buffer, '\0', BUFSIZ);
			if (i > datamodel->tilemap->size.x)
				datamodel->tilemap->size.x = i;
			datamodel->tilemap->size.y++;
			i = 0;
			continue;
		}
		i++;
	}
	close(fd);

	datamodel->tilemap->map = ft_calloc(datamodel->tilemap->size.y, sizeof(char *));
	i = 0;
	while(i < datamodel->tilemap->size.y)
	{
		head = row_list;
		datamodel->tilemap->map[i++] = head->content;
		row_list = row_list->next;
		free(head);
	}
	return (datamodel);
}