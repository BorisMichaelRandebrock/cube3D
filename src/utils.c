#include <stdio.h>
#include "cube3d.h"
#include "libft.h"

void	*__calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(nmemb, size);
	if (!alloc)
		error_quit("Memory error");
	return (alloc);
}

void	error_quit(char *str)
{
	printf(RED"ERROR\n%s"RES, str);
	exit(EXIT_FAILURE);
}
