#include "cube3d.h"
#include "inttypes.h"

#define SHADOW_DEPTH 0.15

uint32_t	px_pixel_shader(uint32_t pixel_data, double distance)
{
	double		level = 0;
	uint32_t	color = 0;
	uint8_t		channel = 0;
	int			shift;
	
	level = ut_clamp(0,1, 1 / (SHADOW_DEPTH * distance));
	shift = 24;
	while (shift)
	{
		channel = pixel_data >> shift;
		channel *= level;
		color += channel << shift;
		shift -= 8;
	}
	return (color);
}

uint32_t	px_decode_pixel(uint8_t *pixel)
{
	uint32_t	color;
	int			shift;

	color = 0x0;
	shift = 24;
	while (shift)
	{
		color |= *pixel++ << shift;
		shift -= 8;
	}
	color |= 0x000000FF;
	return (color);
}