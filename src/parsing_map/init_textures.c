/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:55:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 17:29:21 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function texture_complete check if all the textures are initialized.
*/

static bool	texture_complete(t_data *data)
{
	if (data->texture->north != NULL && data->texture->south != NULL
		&& data->texture->west != NULL && data->texture->east != NULL
		&& data->texture->floor != -1 && data->texture->ceiling != -1)
		return (true);
	return (false);
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
	if (check_valide_variables(line_split) == false)
		return (false);
	if (ft_strncmp(line_split[0], "NO", 3) == 0)
		data->texture->north = ft_strdup(line_split[1]);
	else if (ft_strncmp(line_split[0], "SO", 3) == 0)
		data->texture->south = ft_strdup(line_split[1]);
	else if (ft_strncmp(line_split[0], "WE", 3) == 0)
		data->texture->west = ft_strdup(line_split[1]);
	else if (ft_strncmp(line_split[0], "EA", 3) == 0)
		data->texture->east = ft_strdup(line_split[1]);
	else if (ft_strncmp(line_split[0], "F", 2) == 0)
		data->texture->floor = /*function to turn floor color string in number*/0;
	else if (ft_strncmp(line_split[0], "C", 2) == 0)
		data->texture->ceiling = /*function to turn ceiling color string in number*/0;
	else if (ft_strncmp(line_split[0], "\n", 2) != 0)
		return (false);
	free_2d_array(line_split);
	return (true);
}

/*
The function init_textures parse the map and initialize the textures if the
information are correct.
*/

bool	init_textures(int fd, t_data *data)
{
	char	*line;

	while (texture_complete(data) == false)
	{
		line = get_next_line(fd);
		if (line == NULL)
			msg_error_exit(data, "Memory allocation failed\n");
		if (init_variable(data, line) == false)
		{
			free(line);
			msg_error_exit(data, "Error in the data of texture.\n");
		}
		free(line);
	}
	/*
	Function to check if the textures in the structure are correct.
	*/
	return (true);
}
