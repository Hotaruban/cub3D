/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:02:39 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/27 00:31:58 by jhurpy           ###   ########.fr       */
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

static void	assign_hero(t_data *data)
{
	bool	hero_found;
	int		y;

	hero_found = false;
	y = 0;
	while (data->map[y] != NULL)
	{
		if (data->face_ang != -1)
			hero_found = true;
		if (find_hero_line(data, y) == true && hero_found == true)
			msg_error("Too many hero");
		y++;
	}
	if (data->face_ang == -1)
		msg_error(HERO_NOT_FOUND);
	check_hero_pos(data);
}

/*
The function textures_assigned checks if all the textures are assigned.
Function used in the function create_textures in file assign_data.c.
*/

static bool	textures_assigned(t_data *data)
{
	if (data->texture.north.addr != NULL && data->texture.south.addr != NULL
		&& data->texture.west.addr != NULL && data->texture.east.addr != NULL
		&& data->texture.floor != -1 && data->texture.ceiling != -1)
		return (true);
	return (false);
}

/*
Still have to check the valid data of the textures
*/

static void	create_textures(t_data *data, int fd)
{
	char	*line;
	char	**tab;

	while (textures_assigned(data) == false)
	{
		line = get_next_line(fd);
		if (line == NULL)
			msg_error(TEXTURE_INVALID);
		tab = ft_split(line, ' ');
		free(line);
		assign_textures(data, tab);
		free_tab(tab);
	}
	check_valid_textures(data);
	if (open_file_img(data) == false)
		msg_error(FILE_FAILED);
}

/*
Still have to check the valid data of the map
*/

static void	create_map(t_data *data, int fd)
{
	t_list	*line_list;

	line_list = NULL;
	if (assign_map(fd, &line_list) == false)
		msg_error(MAP_INVALID);
	pass_list_to_tab(data, line_list);
	if (data->map_height == 0)
		msg_error(MAP_NOT_FOUND);
	assign_hero(data);
	check_valid_map(data);
}

void	assign_data(t_data *data, char *path_map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		msg_error(FILE_FAILED);
	data->mlx = mlx_init();
	create_textures(data, fd);
	create_map(data, fd);
	close(fd);
}
