/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_degrees.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:21:56 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "rad.h"

//TODO BORRRAR, no usar grados sexagesimales
//TODO borrar conversiones
double	ut_deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

//TODO borrar conversiones
double	ut_rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
