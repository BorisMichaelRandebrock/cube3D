#include <stdlib.h>
#include <stdio.h>
#include "cube3d.h"
#include "tests.h"

int	main(void)
{
	printf("Test 0 - Cub file loading to datamodel: ");
	if (!load_cub_test())
		error_quit("FAILED\n");
	printf("PASSED\n");

	return (EXIT_SUCCESS);
}