/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 04:38:38 by jhurpy           ###   ########.fr       */
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

static bool	assign_hero(t_data *data)
{
	bool	hero_found;
	int		y;

	hero_found = false;
	y = 0;
	while (data->map[y] != NULL)
	{
		if (data->face_dir != 'C')
			hero_found = true;
		if (find_hero_line(data, y) == true && hero_found == true)
		{
			msg_error("Too many hero");
			return (false);
		}
		y++;
	}
	if (data->face_dir == 'C')
	{
		msg_error("No hero");
		return (false);
	}
	return (true);
}

/*
The function textures_assigned checks if all the textures are assigned.
Function used in the function create_textures in file assign_data.c.
*/

static bool	textures_assigned(t_data *data)
{
	if (NORTH.addr != NULL && SOUTH.addr != NULL
		&& WEST.addr != NULL && EAST.addr != NULL
		&& data->texture.floor != -1 && data->texture.ceiling != -1)
		return (true);
	return (false);
}

/*
Still have to check the valid data of the textures
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
	return (true);
}

/*
Still have to check the valid data of the map
*/

static bool	create_map(t_data *data, int fd)
{
	t_list	*line_list;

	line_list = NULL;
	if (assign_map(fd, &line_list) == false)
		return (false);
	pass_list_to_tab(data, line_list);
	if (assign_hero(data) == false)
		return (false);
	return (true);
}

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
	if (create_map(data, fd) == false)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
