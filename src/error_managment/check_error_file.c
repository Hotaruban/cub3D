/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:57:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 16:29:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The check_error file contains functions that check the validity of the map file
and the arguments.
Check_extention function check if the map file has .cub extention.
Check_access_file function check if the map file exist.
*/

static bool	check_extention(char *path_map)
{
	int len;

	len = ft_strlen(path_map);
	if (len < 5)
		return (false);
	if (ft_strncmp(path_map + len - 4, ".cub", 4))
		return (false);
	return (true);
}

static bool	check_access_file(char *path_map)
{
	int fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	check_error_file(int ac, char *path_map)
{
	if (ac != 2)
		msg_error("Wrong number of arguments!\n");
	if (!check_extention(path_map))
		msg_error("Wrong map file extention!\n");
	if (!check_access_file(path_map))
		msg_error("Map file doesn't exist or not accessible!\n");
	return (true);
}
