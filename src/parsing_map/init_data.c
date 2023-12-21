/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:37:51 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 16:25:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function init_data initialize the data structure.
In a first part parse the map and initialize the textures if the information
are correct.
In a second part initialize the map if the information are correct.
*/

void	init_data(t_data *data, char *path_map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (init_textures(fd, data) == false)
	{
		close(fd);
		free_data(data);
		msg_error_parsing("Error in textures data.\n");
	}
	/*
	Here will be the part for reading the second part of the file for
	init the map.
	Now we wait for determination for the map structure to return.
	*/
	close(fd);
}
