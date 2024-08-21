/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:26:06 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/21 16:11:52 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ansi.h"
#include "cub3d.h"

void	ut_error_quit(char *str)
{
	printf(RED"Error\n%s"RES, str);
	exit(EXIT_FAILURE);
}

void	ut_print_colors(const char *str, const char *color)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, RES, sizeof(RES));
}
