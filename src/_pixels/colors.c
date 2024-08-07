#include "cube3d.h"
#include "inttypes.h"

uint32_t	decode_pixel(uint8_t *pixel)
{
	uint32_t	color;

	color = 0x0;
	color |= *pixel++ << 24;
	color |= *pixel++ << 16;
	color |= *pixel++ << 8;
	color |= *pixel;
	return (color);
}