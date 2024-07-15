#include <stdlib.h>
#include <stdio.h>
#include "cube3d.h"
#include "tests.h"

int	main(void)
{
	printf(CYAN"Test 0 - Cub file loading to datamodel: "RES);
	if (!load_cub_test())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);

	printf(CYAN"Test 1 - Check resource files: "RES);
	if (!resources_test())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);


	return (EXIT_SUCCESS);
}