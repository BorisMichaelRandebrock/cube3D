/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:22:03 by fmontser          #+#    #+#             */
/*   Updated: 2024/08/08 17:22:15 by fmontser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdbool.h>

bool	test_dm_load_tex_path(void);
bool	test_dm_load_colors(void);
bool	test_dm_load_tilemap(void);
bool	test_dm_check_tex_files(void);
bool	test_dm_check_colors(void);
bool	test_dm_check_tilemap(void);
#endif