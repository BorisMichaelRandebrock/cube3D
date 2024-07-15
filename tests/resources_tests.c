#include <stdbool.h>
#include "cube3d.h"



bool    resources_test(void)
{
    t_datamodel dm = {
        .no_tex_path = "../res/north_texture.png",
        .ea_tex_path = "../res/south_textures.jpg"
    };
    if (dm_check_textures(&dm))
        return (true);
    return (false);
}