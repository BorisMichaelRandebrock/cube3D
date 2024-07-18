#include <stdlib.h>
#include <stdio.h>
#include "ansi.h"
#include "cube3d.h"
#include "tests.h"

int	main(void)
{
	printf(CYAN"Test 0 - Datamodel load textures path: "RES);
	if (!test_dm_load_tex_path())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);

	printf(CYAN"Test 1 - Datamodel load colors: "RES);
	if (!test_dm_load_colors())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);


	printf(CYAN"Test 2 - Datamodel load tilemap: "RES);
	if (!test_dm_load_tilemap())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);


	printf(CYAN"Test 3 - Datamodel check texture files: "RES);
	if (!test_dm_check_tex_files())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);

	printf(CYAN"Test 4 - Datamodel check colors: "RES);
	if (!test_dm_check_colors())
		error_quit("FAILED\n");
	printf(GREEN"PASSED\n"RES);

	print_colors("Test 5 - Datamodel check map: ", CYAN);
	if (!test_dm_check_tilemap())
		error_quit("FAILED\n");
	print_colors("PASSED\n",GREEN);

	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}