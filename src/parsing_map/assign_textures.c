/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:04:16 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/26 14:00:22 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function path_texture take the path of the texture, verify if the path is
correct and return it.
*/

static char	*path_texture(t_data *data, char **path)
{
	char	*tmp;

	(void) data;
	if (path[2] != NULL)
	{
		free_2d_array(path);
		msg_error("Too many arguments for texture.\n");
	}
	if (path[1][ft_strlen(path[1]) - 1] == '\n')
		tmp = ft_substr(path[1], 0, ft_strlen(path[1]) - 1);
	else
		tmp = ft_strdup(path[1]);
	free_2d_array(path);
	if (tmp == NULL)
		msg_error("Memory allocation failed\n");
	if (check_extension(tmp, ".xpm") == false)
	{
		free(tmp);
		msg_error("Texture extension is not correct.\n");
	}
	if (check_access_file(tmp) == false)
	{
		free(tmp);
		msg_error("Texture path is not correct.\n");
	}
	return (tmp);
}

/*
The function init_variable take the second argument of the line and save it
in the correct variable.
*/

static bool	init_variable(t_data *data, char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		return (false);
	if (check_valid_variables(line_split) == false)
		return (false);
	if (ft_strncmp(line_split[0], "NO", 3) == 0 && data->texture->north == NULL)
		data->texture->north = path_texture(data, line_split);
	else if (ft_strncmp(line_split[0], "SO", 3) == 0 && data->texture->south == NULL)
		data->texture->south = path_texture(data, line_split);
	else if (ft_strncmp(line_split[0], "WE", 3) == 0 && data->texture->west == NULL)
		data->texture->west = path_texture(data, line_split);
	else if (ft_strncmp(line_split[0], "EA", 3) == 0 && data->texture->east == NULL)
		data->texture->east = path_texture(data, line_split);
	else if (ft_strncmp(line_split[0], "F", 2) == 0 && data->texture->floor == -1)
		data->texture->floor = /*function to turn floor color string in number*/0;
	else if (ft_strncmp(line_split[0], "C", 2) == 0 && data->texture->ceiling == -1)
		data->texture->ceiling = /*function to turn ceiling color string in number*/0;
	else if (ft_strncmp(line_split[0], "\n", 2) != 0)
		return (false);
	//if (line_split)
	//	free_2d_array(line_split);
	return (true);
}

/*
The function assign_complete check if the texture structure is complete.
*/

static bool	assign_complete(t_data *data)
{
	if (data->texture->north != NULL && data->texture->south != NULL
		&& data->texture->west != NULL && data->texture->east != NULL
		&& data->texture->floor != -1 && data->texture->ceiling != -1)
		return (true);
	return (false);
}

/*
The function assign_textures assign the texture structure with the data
from the map file.
*/

bool	assign_textures(int fd, t_data *data)
{
	char	*line;

	while (assign_complete(data) == false)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free_data(data);
			msg_error(MEM_ALLOC_FAILED);
			return (false);
		}
		// to change begin
		if (init_variable(data, line) == false)
		{
			free(line);
			msg_error("Data of textures incorrect\n");
		}
		// to change end
		free(line);
	}

	/*
	Function to check if the textures in the structure are correct.
	*/
	return (true);
}
