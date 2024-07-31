#include <unistd.h>
#include <stdio.h>
#include "ansi.h"
#include "cube3d.h"

void	ut_error_quit(char *str)
{
	printf(RED"ERROR\n%s"RES, str);
	exit(EXIT_FAILURE);
}

void	ut_print_colors(const char *str, const char *color)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, RES, sizeof(RES));
}