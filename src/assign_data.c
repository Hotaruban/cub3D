/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/28 16:58:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The file assign_data assign the data structure with the data
from the map file.
First the function assign_textures assign the textures to the data structure.
Then the function create_map create the map.
Finally the function assign_hero assign the hero to the data structure.
*/

/*
static bool	assign_hero(t_data *data)
{

	return (true);
}
*/

static bool	create_textures(t_data *data, int fd)
{
	char	*line;
	char	**tab;

	while (textures_assigned(data) == false)
	{
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		free(line);
		if (assign_textures(data, tab) == false)
		{
			free_tab(tab);
			return (false);
		}
		free_tab(tab);
	}

	// function to check if the texture are valid.

	return (true);
}

/*
static bool	create_map(t_data *data, int fd)
{
	// function to create the map.

	// function to check if the map is valid.

	return (true);
}
*/

bool	assign_data(t_data *data, char *path_map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		msg_error("Failed to open the file");
		return (false);
	}
	if (create_textures(data, fd) == false)
	{
		close(fd);
		return (false);
	}

	/*
	if (create_map(&data, fd) == false)
	{
		close(fd);
		return (false);
	}

	close(fd);
	
	if (assign_hero(&data) == false)
		return (false);
	*/

	return (true);
}
