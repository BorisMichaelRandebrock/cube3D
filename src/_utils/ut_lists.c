/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:22:18 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/13 15:51:48 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO probablemente no necesario, borrar?
t_list	*ut_sort_rays(t_list *lst)
{
	void	*swap;
	t_list	*start;
	double	a;
	double	b;

	start = lst;
	while (lst->next)
	{
		a = ((t_ray *)lst->content)->length;
		b = ((t_ray *)lst->next->content)->length;
		if (a < b)
		{
			swap = lst->content;
			lst->content = lst->next->content;
			lst->next->content = swap;
			lst = start;
		}
		else
			lst = lst->next;
	}
	lst = start;
	return (lst);
}
