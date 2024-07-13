#include <stdlib.h>
#include <stdio.h>
#include "c3dtests.h"

int	main(void)
{
	printf("Test 0 - Cub file loading to datamodel: ");
	if (!load_cub_test())
	{
		printf("FAILED\n");
		return (EXIT_FAILURE);
	}
	printf("PASSED\n");

	return (EXIT_SUCCESS);
}