/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:57:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/25 13:08:33 by jhurpy           ###   ########.fr       */
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
	{
		msg_error("Wrong number of arguments!");
		return (false);
	}
	if (check_extension(path_map, ".cub") == false)
	{
		msg_error("Wrong map file extention!");
		return (false);
	}
	if (check_access_file(path_map) == false)
	{
		msg_error("Map file doesn't exist or not accessible!");
		return (false);
	}
	return (true);
}
