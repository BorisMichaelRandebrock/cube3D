#include <stdbool.h>
#include "respath.h"
#include "cub3d.h"

bool	test_dm_check_tex_files(void)
{
	t_datamodel test_model =
	{
		.no_tex_path = NO_TEX_PATH,
		.so_tex_path = SO_TEX_PATH,
		.we_tex_path = WE_TEX_PATH,
		.ea_tex_path = EA_TEX_PATH
	};

	//ALL OK
	if (!dm_check_tex_files(&test_model))
		return (false);

	//NO_TEX IS WRONG
	test_model.no_tex_path = "wrong_file_test";
	if (!dm_check_tex_files(&test_model))
		return (false);
	return (true);
}