/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/25 14:06:50 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function assign_map_data assign the data structure with the data
from the map file.
*/

bool	assign_map_data(t_data *data, char *path_map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (assign_textures(fd, data) == false)
		return (false);
	/*
	Here will be the part for reading the second part of the file for
	init the map.
	Now we wait for determination for the map structure to return.
	*/
	close(fd);
	return (true);
}
