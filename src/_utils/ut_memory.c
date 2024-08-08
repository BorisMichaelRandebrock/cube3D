/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:25:56 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 18:26:02 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ut_scalloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(nmemb, size);
	if (!alloc)
		ut_error_quit("Memory error");
	return (alloc);
}

bool	ut_sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		return (true);
	}
	return (false);
}
