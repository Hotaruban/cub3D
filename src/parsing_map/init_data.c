/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:37:51 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/14 02:35:19 by jhurpy           ###   ########.fr       */
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
	int	fd;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		msg_error_parsing("Fail in data allocation\n");
	fd = open(path_map, O_RDONLY);
	if (init_textures(fd, data->texture) == false)
	{
		close(fd);
		free_data(data);
		msg_error_parsing("Error in textures\n");
	}
	// init map wait for determination for the map structure
	close(fd);
}
