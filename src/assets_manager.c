
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

#define ELEMENT_PATH 3

static char	*_load_textures_path(char *buffer)
{
	char	*path;
	path = ft_strdup(buffer);
	*(ft_strchr(path, '\n')) = '\0';
	return (path);
} 

static void	_load_textures(int fd, char *buffer, int i, t_datamodel *datamodel)
{
		 while (read(fd, &buffer[i], 1))
	{
		if (buffer[0] == '\n')
			break;
		if (buffer[i] == '\n')
		{
			if (buffer[0] == 'N' && buffer[1] == 'O')
				datamodel->no_tex_path = _load_textures_path(&buffer[ELEMENT_PATH]);
			if (buffer[0] == 'S' && buffer[1] == 'O')
				datamodel->so_tex_path = _load_textures_path(&buffer[ELEMENT_PATH]);
			if (buffer[0] == 'W' && buffer[1] == 'E')
				datamodel->we_tex_path = _load_textures_path(&buffer[ELEMENT_PATH]);
			if (buffer[0] == 'E' && buffer[1] == 'A')
				datamodel->ea_tex_path = _load_textures_path(&buffer[ELEMENT_PATH]);
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
	_load_textures(fd, buffer, i, datamodel);

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
	close(fd);

	datamodel->tilemap->map = __calloc(datamodel->tilemap->size.y, sizeof(char *));
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
