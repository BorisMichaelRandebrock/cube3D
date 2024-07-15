
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

#define ELEMENT_PATH 3

static void	_load_map_data(t_datamodel *datamodel, t_list *row_list)
{
	t_list	*head;
	int		i;

	i = 0;
	datamodel->tilemap->map = __calloc(datamodel->tilemap->size.y, sizeof(char *));
	while(i < datamodel->tilemap->size.y)
	{
		head = row_list;
		datamodel->tilemap->map[i++] = head->content;
		row_list = row_list->next;
		free(head);
	}
}

static void	_load_tilemap(t_datamodel *datamodel, char *buffer, int fd)
{
	char	*row;
	t_list	*row_list;
	int		i;

	datamodel->tilemap = __calloc(1, sizeof(t_tilemap));
	row_list = NULL;
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
	_load_map_data(datamodel, row_list);
}

// 22222222

int	_rgbtohex(char *buffer)
{	
	int		hex_color;
	char	*rgb;
	char	**split_values;
	int		temp;

	rgb = ft_strdup(&buffer[2]);
	split_values = ft_split(rgb, ',');
	hex_color = 0;
	temp = ft_atoi(split_values[0]);
	temp <<= 24;
	hex_color |= temp;
	temp = ft_atoi(split_values[1]);
	temp <<= 16;
	hex_color |= temp;
	temp = ft_atoi(split_values[2]);
	temp <<= 8;
	hex_color |= temp;
	free(rgb);
	free(split_values);
	return (hex_color);
}

static void	_load_surfaces_color(t_datamodel *datamodel, char *buffer, int fd)
{
	int	color;
	int	i;

	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
			break;
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'F' || buffer[0] == 'C')
			{
				color = _rgbtohex(buffer);
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
	ft_memset(buffer, '\0', BUFSIZ);
}


t_datamodel	*load_cub(char *filename)
{
	int		fd;
	int		i;
	char	buffer[BUFSIZ];
	t_datamodel *datamodel;

	datamodel = __calloc(1, sizeof(t_datamodel));
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

	_load_surfaces_color(datamodel, buffer, fd);
	_load_tilemap(datamodel, buffer, fd);
	close(fd);
	return (datamodel);
}

