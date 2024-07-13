#include <stdio.h>
#include "libft.h"

void	*__calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(nmemb, size);
	if (!alloc)
	{
		perror("Error: Memory error");
		exit(EXIT_FAILURE);
	}
	return (alloc);
}