#include <stdio.h>
#include <unistd.h>
#include "ansi.h"
#include "cube3d.h"
#include "libft.h"

void	*scalloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(nmemb, size);
	if (!alloc)
		error_quit("Memory error");
	return (alloc);
}

bool	sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		return (true);
	}
	return (false);
}

void	error_quit(char *str)
{
	printf(RED"ERROR\n%s"RES, str);
	exit(EXIT_FAILURE);
}

void	print_colors(const char *str, const char *color)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, RES, sizeof(RES));
}
