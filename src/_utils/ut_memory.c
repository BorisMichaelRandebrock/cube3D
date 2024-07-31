#include "cube3d.h"

void	*ut_scalloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(nmemb, size);
	if (!alloc)
		ut_error_quit("Memory error");
	return (alloc);
}

bool	ut_sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		return (true);
	}
	return (false);
}