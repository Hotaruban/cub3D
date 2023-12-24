/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:57:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/24 17:03:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The check_error file contains functions that check the validity of the map file
and the arguments.
*/

bool	check_error_file(int ac, char *path_map)
{
	if (ac != 2)
		msg_error_exit(NULL, "Wrong number of arguments!\n");
	if (check_extension(path_map, ".cub") == false)
		msg_error_exit(NULL, "Wrong map file extention!\n");
	if (!check_access_file(path_map))
		msg_error_exit(NULL, "Map file doesn't exist or not accessible!\n");
	return (true);
}
