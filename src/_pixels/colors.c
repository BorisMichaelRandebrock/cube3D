/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:05:29 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "inttypes.h"

#define SHADOW_DEPTH 0.2

uint32_t	px_pixel_shader(uint32_t pixel_data, double distance)
{
	double		level;
	uint32_t	color;
	uint8_t		channel;
	int			shift;

	level = ut_clamp(0, 1, 1 / (SHADOW_DEPTH * distance));
	color = 0;
	channel = 0;
	shift = 24;
	while (shift)
	{
		channel = pixel_data >> shift;
		channel *= level;
		color += channel << shift;
		shift -= 8;
	}
	color |= 0x000000FF;
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
