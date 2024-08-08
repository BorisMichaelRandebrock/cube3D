/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:34:32 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 17:34:33 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_datamodel	*dm_get(t_datamodel *dm)
{
	static t_datamodel	*datamodel = NULL;

	if (!datamodel && dm)
		datamodel = dm;
	return (datamodel);
}
